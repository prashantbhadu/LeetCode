class Solution {
public:
    int func(vector<int>&piles, int s, int e,vector<vector<int>>&dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int start=piles[s] - func(piles,s+1,e,dp);
        int end=piles[e] - func(piles,s,e-1,dp);
        return dp[s][e]=max(start,end);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n,0));
        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<n;end++){
                int s = piles[start] - dp[start+1][end];
                int e =piles[end] - dp[start][end-1];
                dp[start][end] = max(s,e);
            }
        }
        if(dp[0][n-1]>0) return true;
        else return false;
    }
};