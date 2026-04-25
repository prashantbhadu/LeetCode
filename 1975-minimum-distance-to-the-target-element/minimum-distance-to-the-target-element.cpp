class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int>store;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                store.push_back(i);
            }
        }
        for(int i=0;i<store.size();i++){
            ans=min(ans,abs(store[i]-start));
        }
        return ans;
    }
};