class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        unordered_map<int,int>mpp;
        int rnk=1;
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        for(auto it:temp){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=rnk;
                rnk++;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=mpp[arr[i]];
        }
        return ans;
    }
};