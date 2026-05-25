class Solution {
public:
    int solve(vector<int>&nums,int ind){
        if(ind==nums.size()-1) return nums[nums.size()-1];
        if(ind>=nums.size()) return 0;
        int take=0;
        int not_take=-1e9;
        take=nums[ind]+solve(nums,ind+2);
        not_take=solve(nums,ind+1);
        return  max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int not_take=prev;
            int curr=max(take,not_take);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};