class Solution {
public:
    vector<int>largest;
    void func(int ind, int prev, vector<int>&nums, int n,vector<int>&ans){
        if(ind==n){
            if(largest.size()<ans.size()){
                largest=ans;
            }
            return ;
        } 
        if(prev==-1 || nums[ind]%nums[prev]==0){
            ans.push_back(nums[ind]);
            func(ind+1,ind,nums,n,ans);
            ans.pop_back();
        }
        func(ind+1,prev,nums,n,ans);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=1;
        int lastind=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            ans.push_back(nums[lastind]);
        }
        return ans;
    }
};