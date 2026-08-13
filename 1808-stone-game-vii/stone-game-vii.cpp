class Solution {
public:
    vector<vector<int>>dp;
    int func(vector<int>&stones,int s, int e,vector<int>&pref){
        if(s>=e) return 0 ;
        if(dp[s][e]!=-1) return dp[s][e];
        int right= pref[e-1]-(s>0?pref[s-1]:0) - func(stones,s,e-1,pref);
        int left = pref[e]-pref[s]-func(stones,s+1,e,pref);
        return dp[s][e]=max(left,right);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int>pref(n,0);
        dp.resize(n,vector<int>(n,-1));
        pref[0]=stones[0];
        for(int i=1;i<n;i++){
            pref[i]=stones[i]+pref[i-1];
        }
        return func(stones,0,n-1,pref);
    }
};