class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(n*m);
        vector<vector<int>>mat(n,vector<int>(m,0));
        mat=grid;
        for(int l=0;l<k;l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==n-1 && j==m-1){
                        mat[0][0]=grid[i][j];
                    }
                    else if(j==m-1){
                        mat[i+1][0]=grid[i][j];
                    }
                    else mat[i][j+1]=grid[i][j];
                }
            }
            grid=mat;
        }
        return mat;
    }
};