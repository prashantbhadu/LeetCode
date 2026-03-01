class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=1;
        int n=nums.size();
        int end=nums.size()-2;
        int mid=start+(end-start)/2;
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-2]<nums[n-1]) return n-1;
        while(start<=end){
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if( nums[mid]<nums[mid+1]){

                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return 0;

    }
};