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
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){ 
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int left=1e9;
                int up=1e9;
                if(i>=1) up=grid[i][j] + dp[i-1][j];
                if(j>=1) left=grid[i][j] + dp[i][j-1];
                dp[i][j]=min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
};