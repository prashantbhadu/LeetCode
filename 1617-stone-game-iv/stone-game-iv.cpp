class Solution {
public:
    bool func(int n,vector<vector<int>>&dp,int flag){
        if(n==0){
            if(flag==0) return false;
            else return true;
        }
        if(dp[flag][n]!=-1) return dp[flag][n];
        if(flag==0){
            for(int i=1;i*i<=n;i++){
                if(func(n-i*i,dp,1)) return dp[flag][n]=true;
            }
            return dp[flag][n]=false;
        }
        else{
            for(int i=1;i*i<=n;i++){
                if(func(n-i*i,dp,0)) continue;
                return dp[flag][n]=false;
            }
           

        }
        return dp[flag][n]=true;;

    }
    bool winnerSquareGame(int n) {
        vector<vector<int>>dp(2,vector<int>(n+1,-1));
        return func(n,dp,0);
    }
};