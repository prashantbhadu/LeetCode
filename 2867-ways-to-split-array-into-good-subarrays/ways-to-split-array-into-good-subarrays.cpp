class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
       long long ans=1;
       int prevone=-1;
       int modo=1e9+7;

       for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            if(prevone!=-1){
                ans=(ans*(i-prevone))%modo;
            }
            prevone=i;
        }
       }
        return prevone==-1?0:ans;
    }
};