class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int ans=INT_MIN;
        int temp=0;
        while(r<nums.size()){
            if(nums[r]==0) temp++;
            while(temp>k){
                if(nums[l]==0) temp--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};