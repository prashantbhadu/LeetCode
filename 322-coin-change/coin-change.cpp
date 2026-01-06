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
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};