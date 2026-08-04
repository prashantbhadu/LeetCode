class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp.insert({nums[i],1});
                //mpp[nums]++;
            }
            else mpp[nums[i]]++;
        }
        int ans;
        for(auto &[it,frq]:mpp){

            if(frq<3){
                ans=it;
                break;
            }
        }
        return ans;
    }
};