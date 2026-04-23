class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        vector<long long>ans(n,0);
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto& it: mpp){
            vector<int> &vec = it.second;
            int m=vec.size();
            vector<long long>prefix(m,0);
            prefix[0]=vec[0];
            for(int i=1;i<m;i++){
                prefix[i]=prefix[i-1]+vec[i];
            }
            for(int i=0;i<m;i++){
                long long left =0, right=0;
                if(i>0) left=(long long)vec[i]*i - prefix[i-1];
                if(i<m-1){
                    right = (prefix[m-1]-prefix[i])-(long long)vec[i]*(m-i-1);

                }
                ans[vec[i]]=left+right;
            }

        }
        return ans;

    }
};