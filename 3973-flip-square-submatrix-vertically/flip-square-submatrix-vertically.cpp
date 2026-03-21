class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int l=x,m=x+k-1;l<m;l++,m--){
            for(int j=y;j<k+y;j++){
                swap(grid[l][j],grid[m][j]);
            }
        }
        return grid;
    }
};