class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        int n=arr.size();
        unordered_map<int,int>mpp;
        int rnk=1;
        for(auto it:temp){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=rnk;
                rnk++;
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=mpp[arr[i]];
        }
        return ans;

    }
};