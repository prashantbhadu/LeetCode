class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        while(j<n){
            sum+=nums[j];
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                cnt=cnt+mpp[rem];
            }
            mpp[sum]++;
            j++;
        }
        return cnt;
    }
};