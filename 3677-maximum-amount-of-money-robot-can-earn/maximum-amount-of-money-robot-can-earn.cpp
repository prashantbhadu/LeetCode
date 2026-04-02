class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1e9))
        );

        // 🔹 Base case (bottom-right)
        for(int k = 0; k <= 2; k++){
            if(coins[m-1][n-1] < 0 && k > 0)
                dp[m-1][n-1][k] = max(0, coins[m-1][n-1]);
            else
                dp[m-1][n-1][k] = coins[m-1][n-1];
        }

        // 🔹 Fill DP from bottom-right to top-left
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) continue;

                for(int k = 0; k <= 2; k++){
                    int best = -1e9;

                    // move right
                    if(j + 1 < n){
                        if(coins[i][j] < 0){
                            // neutralize
                            if(k > 0)
                                best = max(best, dp[i][j+1][k-1]);
                            // don't neutralize
                            best = max(best, coins[i][j] + dp[i][j+1][k]);
                        } else {
                            best = max(best, coins[i][j] + dp[i][j+1][k]);
                        }
                    }

                    // move down
                    if(i + 1 < m){
                        if(coins[i][j] < 0){
                            if(k > 0)
                                best = max(best, dp[i+1][j][k-1]);
                            best = max(best, coins[i][j] + dp[i+1][j][k]);
                        } else {
                            best = max(best, coins[i][j] + dp[i+1][j][k]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[0][0][2];
    }
};