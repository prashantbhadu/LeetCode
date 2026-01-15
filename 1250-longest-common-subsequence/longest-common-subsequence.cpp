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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};