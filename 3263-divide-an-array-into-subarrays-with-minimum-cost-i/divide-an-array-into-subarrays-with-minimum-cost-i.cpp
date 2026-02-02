class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n= nums.size();
        int sum=nums[0];
        int min1=100;
        int min2=200;
        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x<min2){
                if(x<min1){
                    min2=min1;
                    min1=x;
                }
                else{
                    min2=x;
                }
            }
        }
        sum+=min1+min2;
        return sum;
    }
};