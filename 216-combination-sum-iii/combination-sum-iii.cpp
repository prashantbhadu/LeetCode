class Solution {
public:
    void recur(int ind, int target, vector<vector<int>>&ans,vector<int>&ds,int k){
        if(target==0 && k==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i>target || k<=0)break;
            ds.push_back(i);
            recur(i+1,target-i,ans,ds,k-1);
            ds.pop_back();   
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        recur(1,n,ans,ds,k);
        return ans;
    }
};