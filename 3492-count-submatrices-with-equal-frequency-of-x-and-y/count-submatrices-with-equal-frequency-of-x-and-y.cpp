class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int cnt=0;
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>sum(n,vector<int>(m,0));
       vector<vector<int>>cntx(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val=0, x=0;
            if(grid[i][j]=='X'){
                val=1;
                x=1;
            }
            else if(grid[i][j]=='Y') val=-1;
            sum[i][j]=val;
            cntx[i][j]=x;
            if(i>0){
                sum[i][j]+=sum[i-1][j];
                cntx[i][j]+=cntx[i-1][j];
            }
            if(j>0){
                sum[i][j]+=sum[i][j-1];
                cntx[i][j]+=cntx[i][j-1];
            }
            if(i>0 && j>0){
                sum[i][j]-=sum[i-1][j-1];
                cntx[i][j]-=cntx[i-1][j-1];
            }
            if(sum[i][j]==0 && cntx[i][j]>0) cnt++;
        }
        

    }
        return cnt;
    }
};