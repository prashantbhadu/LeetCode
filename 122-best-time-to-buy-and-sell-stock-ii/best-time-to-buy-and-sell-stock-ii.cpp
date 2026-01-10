class Solution {
public:
    int solve(int ind, int n, int buy,vector<int>&arr,vector<vector<int>>&dp){
        if(ind==n) return 0;
        int profit=-1e9;
        int not_profit=-1e9;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit= -arr[ind]+solve(ind+1,n,0,arr,dp);
            not_profit=solve(ind+1,n,1,arr,dp);
        }
        else{
            profit=arr[ind]+solve(ind+1,n,1,arr,dp);
            not_profit=solve(ind+1,n,0,arr,dp);
        }
        return dp[ind][buy]=max(profit,not_profit);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,prices,dp);
    }
};