class Solution {
public:
    bool func(int i, int j, string s, string p){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(j<0) return false;
        if(s[i]==p[j] || p[j]=='?'){
            return func(i-1,j-1,s,p);
        }
        if(p[j]=='*'){
           return func(i-1,j,s,p) || func(i,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(int j=1;j<=i;j++){
                if(p[j-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][i]=flag;
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