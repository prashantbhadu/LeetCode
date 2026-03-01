class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end=nums.size()-1;
        int start=0;
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end){
            if(nums[mid]==target) return mid;
            else if(nums[start]<=nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
                    end=mid-1;
                    ans=mid;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target<=nums[end] && target>nums[mid]){
                    start=mid+1;
                    ans=mid;
                }
                else{
                    end=mid-1;
                }
            }
            mid=start+(end-start)/2;
        }
        if(ans==-1)return -1;
        return nums[ans]==target?ans:-1;
    }
};