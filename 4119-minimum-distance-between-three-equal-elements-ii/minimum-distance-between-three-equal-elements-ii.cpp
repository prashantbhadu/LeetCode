class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
            if(mpp[nums[i]].size()>=3){
                int n=mpp[nums[i]].size();
                ans=min(ans,mpp[nums[i]][n-1]-mpp[nums[i]][n-3]);
            }
        }
       
        return ans==INT_MAX?-1:2*ans;

    }
};