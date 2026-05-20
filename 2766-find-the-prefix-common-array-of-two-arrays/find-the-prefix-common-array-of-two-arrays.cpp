class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<A.size();i++){
            mpp[A[i]]++;
            mpp[B[i]]++;
            if(A[i]==B[i]) cnt++;
            else{
                if(mpp[A[i]]==2)cnt++;
                if(mpp[B[i]]==2)cnt++;
            }
            
            ans.push_back(cnt);
        }
        return ans;
    }
};