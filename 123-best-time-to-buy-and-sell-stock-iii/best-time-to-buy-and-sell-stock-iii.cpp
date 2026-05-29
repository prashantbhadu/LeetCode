class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k>=0;k--){
                    int profit=-1e9;
                    int not_profit=-1e9;
                    if(j==0){
                        profit=-prices[i]+dp[i+1][1][k];
                        not_profit=dp[i+1][0][k];
                    }
                    else{
                        profit=prices[i]+dp[i+1][0][k+1];
                        not_profit=dp[i+1][1][k];
                    }
                    dp[i][j][k]=max(profit,not_profit);
                }
            }
        }
        return dp[0][0][0];
    }
};