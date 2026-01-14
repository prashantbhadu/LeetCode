class Solution {
public:
    int solve(int ind,int buy,int n,vector<int>&arr,int rem,vector<vector<vector<int>>>&dp){
        if(ind==n) return 0;
        if(rem==2) return 0;
        int profit=-1e9;
        int not_profit=-1e9;
        if(dp[ind][buy][rem]!=-1) return dp[ind][buy][rem];
        if(buy==1){
            profit=-arr[ind]+solve(ind+1,0,n,arr,rem,dp);
            not_profit=solve(ind+1,1,n,arr,rem,dp);
        }
        else{
            profit=arr[ind]+solve(ind+1,1,n,arr,rem+1,dp);
            not_profit=solve(ind+1,0,n,arr,rem,dp);
        }
        return max(profit,not_profit);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<3;cap++){
                    int profit=-1e9;
                    int not_profit=-1e9;
                    if(buy==1){
                        curr[buy][cap]= max( -prices[ind]+after[0][cap],after[1][cap]);
                        
                    }
                    else{
                       curr[buy][cap]=max(prices[ind]+after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};