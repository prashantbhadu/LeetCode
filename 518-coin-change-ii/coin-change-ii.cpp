class Solution {
public:
    int solve(int ind, int k, vector<int>&arr,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(ind ==0){
            if(k%arr[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][k]!=-1) return dp[ind][k];
        int pick=0;
        if(k>=arr[ind]) pick=solve(ind,k-arr[ind],arr,dp);
        int not_pick=solve(ind-1,k,arr,dp);
        return dp[ind][k]=pick+not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};