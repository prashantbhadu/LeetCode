class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int sum=0;
            while(val>0){
                int digit=val%10;
                sum+=digit;
                val/=10;
            }
            mini=min(mini,sum);
        }
        return mini;
    }
};