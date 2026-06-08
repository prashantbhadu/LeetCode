class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(auto val:nums){
            if(val<pivot) ans.push_back(val);
        }
        for(auto val:nums){
            if(val==pivot) ans.push_back(val);
        }
        for(auto val:nums){
            if(val>pivot) ans.push_back(val);
        }
        return ans;
    }
};