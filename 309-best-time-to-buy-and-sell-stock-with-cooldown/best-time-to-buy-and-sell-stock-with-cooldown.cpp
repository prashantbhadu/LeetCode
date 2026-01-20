class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=-1e9;
                int not_profit=-1e9;
                if(j==1){
                    profit=-prices[i]+dp[i+1][0];
                    not_profit=dp[i+1][1];
                }
                else{
                    
                    profit=prices[i]+dp[i+2][1];
                    not_profit=dp[i+1][0];
                }
                dp[i][j]=max(profit,not_profit);
            }
        }
        return dp[0][1];
        
    }
};