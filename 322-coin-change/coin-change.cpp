class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if (amount==0) return 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int stay=1e9;
                if(target>=coins[i]){
                    stay=1+dp[i][target-coins[i]];
                }
                int move=dp[i-1][target];
                dp[i][target]=min(stay,move);
            }
        }
        return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];
    }
};