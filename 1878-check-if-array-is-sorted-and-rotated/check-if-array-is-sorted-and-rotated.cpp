class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1) return true;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]) cnt++;
        }
        if(cnt>1) return false;
        else if(cnt>=1 && nums[0]<nums[nums.size()-1]) return false;
        return true;
    }
};