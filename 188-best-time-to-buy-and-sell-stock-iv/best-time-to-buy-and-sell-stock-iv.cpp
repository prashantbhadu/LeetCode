class Solution {
public:
    int solve(int ind, int k, int buy, int size, vector<int>&arr){
        if(ind==size) return 0;
        if(k==0) return 0;
        int profit=-1e9,not_profit=-1e9;
        if(buy==1){
            profit=-arr[ind]+solve(ind+1,k,0,size,arr);
            not_profit=solve(ind+1,k,1,size,arr);
        }
        else{
            profit=arr[ind]+solve(ind+1,k-1,1,size,arr);
            not_profit=solve(ind+1,k,0,size,arr);
        }
        return max(profit,not_profit);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit=-1e9;
                    int not_profit=-1e9;
                    if(buy==1){
                        profit=-prices[ind]+dp[ind+1][0][cap];
                        not_profit=dp[ind+1][1][cap];
                    }
                    else{
                        profit=prices[ind]+dp[ind+1][1][cap-1];
                        not_profit=dp[ind+1][0][cap];
                    }
                    dp[ind][buy][cap]=max(profit,not_profit);
                }
            }
        }
        return dp[0][1][k];
    }
};