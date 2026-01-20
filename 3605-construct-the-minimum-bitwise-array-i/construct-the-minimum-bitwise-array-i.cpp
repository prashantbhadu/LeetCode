class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool check=false;
            for(int k=1;k<=1000;k++){
                if((k|k+1)==nums[i]){
                    ans.push_back(k);
                    check=true;
                    break;
                }
            }
            if(!check) ans.push_back(-1);
        }
        return ans;
    }
};