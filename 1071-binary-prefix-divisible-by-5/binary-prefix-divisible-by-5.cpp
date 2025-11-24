class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
      
        int sum=0;
        vector<bool>ans(n);
       
        for(int i=0;i<n;i++){
            sum=(sum*2 + nums[i])%5;
            if(sum==0){
                ans[i]=true;
            }
        }
        return ans;
    }
};