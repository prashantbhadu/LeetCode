class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int k=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        int ans;
        for(int i=0;i<k;i++){
            if(mp[nums[i]]==k/2){ 
                ans=nums[i];
                break;
            }
        }
        return ans;

    }
};