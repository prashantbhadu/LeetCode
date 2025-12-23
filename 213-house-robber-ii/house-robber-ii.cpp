class Solution {
public:
   
    int solve(int m,vector<int>&arr, vector<int>&dp){
        if(m==0)return arr[0];
        if(m<0) return 0;
        if(dp[m]!=-1) return dp[m];
        int pick=arr[m]+solve(m-2,arr,dp);
        int notpick=0+solve(m-1,arr,dp);

        return dp[m]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        int l=nums.size();
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<l;i++){
            if(i!=l-1) arr1.push_back(nums[i]);
            if(i!=0) arr2.push_back(nums[i]);
        }
        if(l==1) return nums[0];
        vector<int>dp1(arr1.size(),-1);
        vector<int>dp2(arr2.size(),-1);
         int first=solve(arr1.size()-1,arr1,dp1);
         int second=solve(arr2.size()-1,arr2,dp2);
         return max(first,second);

        
    }
};