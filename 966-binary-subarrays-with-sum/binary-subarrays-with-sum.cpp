class Solution {
public:
    int prev(vector<int>&nums, int goal){
        if(goal<0) return 0;
        int r=0;
        int l=0;
        int temp=0;
        int ans=0;
        int sum=0;
        while(l<nums.size() && r<nums.size()){
           sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            if(sum<=goal) ans=ans+r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return prev(nums,goal)-prev(nums,goal-1);
    }
};