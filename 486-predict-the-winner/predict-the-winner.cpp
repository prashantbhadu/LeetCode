class Solution {
public:
   
    int func(int start,int end,vector<int>&nums){
        if(start>end) return 0;
        int p1_s=nums[start] - func(start+1,end,nums);
        int p1_e = nums[end] - func(start,end-1,nums);
        return max(p1_s,p1_e);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size()-1;
        return func(0,n,nums)>=0;
        
    }
};