class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++) totsum+=nums[i];
        if(totsum%2!=0) return false;
        vector<vector<bool>>dp(n,vector<bool>((totsum/2)+1,0));
        int target=totsum/2;
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(target>= nums[0]) dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int k=1;k<=target;k++){
                bool pick=false;
                if(k>=nums[ind]) pick=dp[ind-1][k-nums[ind]];
                bool notpick=dp[ind-1][k];
                dp[ind][k]=(pick|notpick);
                
                dp[ind][k]=(pick|notpick);
            }
        }
        return dp[n-1][target];
    }
};