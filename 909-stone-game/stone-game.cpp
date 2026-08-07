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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(func(piles,0,n-1,dp)>0) return true;
        else return false;
    }
};