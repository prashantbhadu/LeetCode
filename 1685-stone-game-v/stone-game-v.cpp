class Solution {
public:
    vector<vector<int>>dp;
    int solve(int s,int e, vector<int>&pff, vector<int>&arr){
        if(s== e) return 0;
        int ans=0;
        if(dp[s][e]!=-1) return dp[s][e];
        for(int i=s;i<e;i++){
            int sum1 = pff[i] - (s>0? pff[s-1]:0);
            int sum2 = pff[e]-pff[i];
            if(sum1>sum2){
                ans=max(ans,sum2+solve(i+1,e,pff,arr));
            }
            else if(sum2>sum1){
                ans = max(ans,sum1+solve(s,i,pff,arr));
            }
            else {
                ans=max({ans,sum2+solve(i+1,e,pff,arr),sum1+solve(s,i,pff,arr)});
               
            }
        }
        return dp[s][e]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>pref(n,0);
        dp.resize(n+1,vector<int>(n+1,-1));
        pref[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+stoneValue[i];
        }
        return solve(0,n-1,pref,stoneValue);
    }
};