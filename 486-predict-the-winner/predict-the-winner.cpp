class Solution {
public:
   
    int func(int start,int end,vector<int>&nums){
        if(start>end) return 0;
        int p1_s=nums[start] - func(start+1,end,nums);
        int p1_e = nums[end] - func(start,end-1,nums);
        return max(p1_s,p1_e);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<=n;end++){
                int p1_s=nums[start] - dp[start+1][end];
                int p1_e = nums[end-1] - dp[start][end-1];
                dp[start][end]=max(p1_s,p1_e);
            }
        }
        return dp[0][n]>=0;
        
    }
};