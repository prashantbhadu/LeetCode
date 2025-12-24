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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};