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
        // vector<vector<int>>dp(m,vector<int>(n,0));
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;
        // dp[0][0]=1;
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                    continue;
                }
                int down=0;
                int right=0;
                if(i>0 && obstacleGrid[i][j]!=1){
                    down=prev[j];
                }
                if(j>0 && obstacleGrid[i][j]!=1){
                    right=temp[j-1];
                }
                temp[j]=down+right;
            }
            prev=temp;
        }
        return prev[n-1];
    }
};