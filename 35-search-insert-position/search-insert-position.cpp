class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                return ans;
            }
            else if(nums[mid]>target){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        if(ans==-1) return nums.size();
        return ans;
    }
};