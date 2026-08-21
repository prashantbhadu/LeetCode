class Solution {
public:
    int minDistance(string word1, string word2) {
         string s2=word2;
        string s=word1;
        int n=s.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=0;
                int ans2=0;
                if(s[i-1]==s2[j-1]){
                    ans=1+dp[i-1][j-1];
                }
                else {
                    ans2=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=max(ans,ans2);
            }
        }
        return (n-dp[n][m])+(m-dp[n][m]);
    }
};