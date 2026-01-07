class Solution {
public:
    int solve(int ind, int k, vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(k%coins[ind]==0) return k/coins[ind];
            return 1e9;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int pick=1e9;
        if(k>=coins[ind]){
            pick=solve(ind,k-coins[ind],coins,dp)+1;
        }
        int not_pick=solve(ind-1,k,coins,dp)+0;
        return dp[ind][k]=min(pick,not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0) return 0;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int k=0;k<=amount;k++){
                int pick=1e9;
                if(k>=coins[ind]) pick=dp[ind][k-coins[ind]]+1;
                int not_pick=dp[ind-1][k]+0;
                dp[ind][k]=min(pick,not_pick);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
    }
};