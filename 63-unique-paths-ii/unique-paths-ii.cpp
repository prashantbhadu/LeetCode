class Solution {
public:
    int solve(int x,int y,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
            if(x<0 || y<0) return 0;
            if(x==0 && y==0 && obstacleGrid[x][y]==0) return 1;
            if(obstacleGrid[x][y]==1) return 0;
            if(dp[x][y]!=-1) return dp[x][y];
        
        
            int left=solve(x,y-1,dp,obstacleGrid);
            int right=solve(x-1,y,dp,obstacleGrid);
        
            return dp[x][y]=left+right;
        }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
       // if(n==1 && m==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};