class Solution {
public:
    int func(int mid, vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        return sum;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int last=*max_element(nums.begin(),nums.end());
        int mid=start+(last-start)/2;
        int ans=0;
        while(start<=last){
            if(func(mid,nums)<=threshold){
                ans=mid;
                last=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(last-start)/2;
        }
        return ans;
    }
};