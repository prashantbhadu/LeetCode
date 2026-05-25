class Solution {
public:
    int solve(int x,int y, vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(x==0 && y==0 )return grid[x][y];
        if(x<0 || y<0) return 1e9;
        if(dp[x][y]!=-1)return dp[x][y];
        int left = grid[x][y]+ solve(x,y-1,grid,dp);
        int right = grid[x][y] + solve(x-1,y,grid,dp);
        return dp[x][y]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){ 
                    temp[j]=grid[i][j];
                    continue;
                }
                int left=1e9;
                int up=1e9;
                if(i>0) up=grid[i][j] + prev[j];
                if(j>0) left=grid[i][j] + temp[j-1];
                temp[j]=min(up,left);
            }
            prev=temp;
        }
        return prev[m-1];
    }
};