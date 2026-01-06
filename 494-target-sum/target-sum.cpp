class Solution {
public:
    int solve(int ind,int sum, int k, vector<int>&nums){
        if(ind==0){
            if(sum==k) return 1;
            return 0;
        }
        int add=solve(ind-1,sum+nums[ind-1],k,nums);
        int sub=solve(ind-1,sum-nums[ind-1],k,nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return (solve(n-1,nums[n-1],target,nums)+solve(n-1,-nums[n-1],target,nums));
    }
};