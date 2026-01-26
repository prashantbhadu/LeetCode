class Solution {
public:
    int solve(int ind,int sum, int k, vector<int>&nums){
        if(ind<0){
            if(sum==k) return 1;
             else return 0;
        }
        int add=solve(ind-1,sum+nums[ind],k,nums);
        int sub=solve(ind-1,sum-nums[ind],k,nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return (solve(n-1,0,target,nums));
    }
};