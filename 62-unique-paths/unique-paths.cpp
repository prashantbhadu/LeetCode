class Solution {
public:
    int solve(int x,int y,vector<vector<int>>&dp){
        if(x<0 || y<0) return 0;
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
       
       
        int left=solve(x,y-1,dp);
        int right=solve(x-1,y,dp);
    
        return dp[x][y]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        // for(int i=0;i<n;i++) dp[0][i]=1;
        // for(int i=0;i<m;i++) dp[i][0]=1;
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left=0;
                int up=0;
                if(j>0)
                    left=dp[i][j-1];
                if(i>0)
                    up=dp[i-1][j];
                dp[i][j]=left+up;
            }
        }
        return dp[m-1][n-1];
    }
};