class Solution {
public:
    int solve(int ind,int sum, int k, vector<int>&nums){
        if(ind<0){
            if(sum==k) return 1;
             else return 0;
        }
        int add=solve(ind-1,sum+nums[ind],k,nums);
        int sub=solve(ind-1,sum-nums[ind],k,nums);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum+target)%2!=0 || abs(target)>sum) return 0;
        int newk= (sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(newk+1,0));
        if( nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(newk>=nums[0] && nums[0]!=0) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int k=0;k<=newk;k++){
                int not_take=dp[i-1][k];
                int take=0;
                if(k>=nums[i]) take=dp[i-1][k-nums[i]];
                dp[i][k]= take + not_take;
            }
        }
        return dp[n-1][newk];
    }
};