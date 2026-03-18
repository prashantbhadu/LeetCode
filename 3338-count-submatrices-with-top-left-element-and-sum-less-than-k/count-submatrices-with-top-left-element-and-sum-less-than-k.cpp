class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int cnt=0;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        for(int i=0;i<grid.size();i++){
            int sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
                if(sum<=k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};