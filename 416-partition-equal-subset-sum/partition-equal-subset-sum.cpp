class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        int n=nums.size();
        // vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        // for(int i=0;i<n;i++){
        //     dp[i][0]=true;
        // }
        vector<bool>prev(target+1,0);
        prev[0]=true;
        if(target>=nums[0]) prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            vector<bool>temp(target+1,0);
            for(int j=0;j<=target;j++){
                bool pick=false;
                if(j>=nums[i]) pick=prev[j-nums[i]];
                bool not_pick=prev[j];
                temp[j]=pick | not_pick;
            }
            prev=temp;
        }
        return prev[target];
    }
};