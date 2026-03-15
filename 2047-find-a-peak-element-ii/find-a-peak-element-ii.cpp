class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    bool possible(int i,int j,vector<vector<int>>& mat){
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && y>=0 && x<mat.size() && y<mat[0].size()){
                if(mat[i][j]<mat[x][y]) return false ;
            }
            else continue;
        }
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(possible(i,j,mat)){
                    return {i, j};  
                }
            }
        }
        
        return {-1, -1}; 
    }
};