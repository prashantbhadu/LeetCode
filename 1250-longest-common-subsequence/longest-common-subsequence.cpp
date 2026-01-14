class Solution {
public:
    int f(int n,int m, string& st1,string& st2,vector<vector<int>>&dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(st1[n]==st2[m]) return dp[n][m]=1+f(n-1,m-1,st1,st2,dp);
        return dp[n][m]=max(f(n-1,m,st1,st2,dp),f(n,m-1,st1,st2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};