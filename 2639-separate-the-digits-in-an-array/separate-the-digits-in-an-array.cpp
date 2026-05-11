class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int number=nums[i];
            stack<int>st;
            while(number>0){
                int digit=number%10;
                st.push(digit);
                number/=10;
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};