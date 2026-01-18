class Solution {
public:
    bool solve(int i, int j, string&s, string&p){
        if(i<0) return true;
        if(j<0) return false;
        if(s[i]==p[j] || p[j]=='?'){
            return solve(i-1,j-1,s,p);
        }
        return solve(i,j-1,s,p);
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
       vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
       dp[0][0]=true;
       for(int j=1;j<=m;j++){
        bool flg=true;
        for(int k=1;k<=j;k++){
            if(p[k-1]!='*'){
                flg=false;
                break;

            }
        }
        dp[0][j]=flg;
       }
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                dp[i][j]= (dp[i-1][j] || dp[i][j-1]);
            }
            else dp[i][j]=false;
        }
       }
       return dp[n][m];

    }
};