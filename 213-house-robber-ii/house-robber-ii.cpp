class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int take=nums[i];
            if(i>1)take+=dp[i-2];
            int not_take=dp[i-1];
            dp[i]=max(take,not_take);
        }
        vector<int>dp1(n,0);
                dp1[1]=nums[1];
            for(int i=2;i<n;i++){
                int take=nums[i];
                if(i>2) take+=dp1[i-2];
                int not_take=dp1[i-1];
                dp1[i]=max(take,not_take);
        }
        int ans=max(dp1[n-1],dp[n-2]);
        return ans;
    }
};

