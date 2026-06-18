class Solution {
public:
    int findGCD(vector<int>& nums) {
        int lar=*max_element(nums.begin(),nums.end());
        int small=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=lar;i>=1;i--){
            if(lar%i==0 && small%i==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};