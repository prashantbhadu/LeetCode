class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int>less;
        queue<int>great;
        int cnt_pivot=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                great.push(nums[i]);
            }
            else if(nums[i]<pivot){
                less.push(nums[i]);
            }
            else cnt_pivot++;
        }
        cout<<cnt_pivot<<endl;
        vector<int>ans;
        while(!less.empty()){
            int val=less.front();
            less.pop();
            ans.push_back(val);
        }
        while(cnt_pivot>0){
            ans.push_back(pivot);
            cnt_pivot--;
        }
        while(!great.empty()){
            int val=great.front();
            great.pop();
            ans.push_back(val);
        }
        return ans;
    }
};