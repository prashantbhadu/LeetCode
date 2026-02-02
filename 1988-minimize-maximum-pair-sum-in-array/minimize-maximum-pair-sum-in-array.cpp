class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int y=nums.size()-1;
        int maxi=-1e9;
        while(i<y){
            int sum=0;
            sum=nums[i]+nums[y];
            maxi=max(maxi,sum);
            i++;
            y--;
        }
        return maxi;
    }
};