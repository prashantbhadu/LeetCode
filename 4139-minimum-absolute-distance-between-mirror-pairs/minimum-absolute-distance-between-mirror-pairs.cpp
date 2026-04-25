class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i])){
                ans=min(ans,i-mpp[nums[i]]);
            }
            int x=nums[i];
            int k=0;
            while(x){
                k=k*10+x%10;
                x=x/10;
            }
            mpp[k]=i;
        }

        return ans==INT_MAX?-1:ans;
    }
};