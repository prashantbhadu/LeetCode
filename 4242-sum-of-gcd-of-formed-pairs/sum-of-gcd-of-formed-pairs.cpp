class Solution {
public:
    
    long long gcdSum(vector<int>& nums) {
        long long sum=0;
        int mx=INT_MIN;
        int n=nums.size();
        vector<int>prfgcd(n);
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            prfgcd[i]=gcd(nums[i],mx);
        }
        sort(prfgcd.begin(),prfgcd.end());
        int i=0;
        int j=n-1;
        while(i<j){
            sum+=gcd(prfgcd[i],prfgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};