class Solution {
public:
    int func(int i,int j,string word1,string word2){
        if(i<0 ) return j+1;
        if(j<0 ) return i+1;
        if(word1[i]==word2[j]) return func(i-1,j-1,word1,word2);
        return min({1+func(i-1,j,word1,word2),1+func(i-1,j-1,word1,word2),1+func(i,j-1,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=1e9;
                int ans1=1e9;
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=min({1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
                
            }
        }
        return dp[n][m];
    }
};