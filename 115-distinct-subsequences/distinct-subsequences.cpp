class Solution {
public:
    int solve(int ind,string ans, string& s,string& t){
        if(ind==0){
            reverse(ans.begin(),ans.end());
            if(ans==t) return 1;
            else return 0;
        }
        string newans=ans+s[ind-1];
        int pick=solve(ind-1,newans,s,t);
        int not_pick=solve(ind-1,ans,s,t);
        return pick+not_pick;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long >>dp(n+1,vector< unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};