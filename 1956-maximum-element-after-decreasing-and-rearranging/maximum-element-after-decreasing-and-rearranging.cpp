class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=1;
        for(int i=1;i<arr.size();i++){
            if(abs(ans-arr[i])<=1){
                ans=max(ans,arr[i]);
            }
            else{
                ans=ans+1;
            }
        }
        return ans;
    }
};