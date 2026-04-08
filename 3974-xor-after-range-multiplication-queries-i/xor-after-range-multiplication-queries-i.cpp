class Solution {
public:
    int modo=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        for(auto cmd:queries){
            int ind=cmd[0];
            int range=cmd[1];
            int val=cmd[3];
            int inc=cmd[2];
            while(ind<=range && ind<n){
                nums[ind]=(1LL*nums[ind]*val)%modo;
                if(inc==0) break;
                ind+=inc;
            }  
        }
         int ans=0;
            for(int i=0;i<n;i++){
                ans=ans^nums[i];
            }
        return ans;
    }
};