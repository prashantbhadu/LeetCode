class Solution {
public:
    int f(int end,int st, string& s){
        if(st>end){
            return 0;
        }
        if(s[st]==s[end]){
            if(st==end) return 1+f(end-1,st+1,s);
            else{
                return 2+f(end-1,st+1,s);
            }
        }
        return max(f(end-1,st,s),f(end,st+1,s));

    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int st=1;st<=n;st++){
            for(int j=1;j<=n;j++){
                if(s[st-1]==s2[j-1]){
                    dp[st][j]=1+dp[st-1][j-1];
                    }
                else{
                    dp[st][j]=max(dp[st][j-1],dp[st-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};