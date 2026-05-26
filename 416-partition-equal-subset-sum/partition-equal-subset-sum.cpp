class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(target>=nums[0]) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool pick=false;
                if(j>=nums[i]) pick=dp[i-1][j-nums[i]];
                bool not_pick=dp[i-1][j];
                dp[i][j]=pick | not_pick;
            }
        }
        return dp[n-1][target];
    }
};