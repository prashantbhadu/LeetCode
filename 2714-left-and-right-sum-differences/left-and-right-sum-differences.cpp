class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>rs;
        vector<int>ls;
        rs.push_back(0);
        ls.push_back(0);
        int sum=0;
        int last=0;
        for(int i=1;i<n;i++){
            sum+=nums[i-1];
            last+=nums[n-i];
            rs.push_back(sum);
            ls.push_back(last);
        }
        vector<int>ans;
        reverse(ls.begin(),ls.end());
        for(int i=0;i<n;i++){
            cout<<rs[i]<<" "<<ls[i]<<endl;
            int diff=abs(rs[i]-ls[i]);
            ans.push_back(diff);
        }
        return ans;
    }
};