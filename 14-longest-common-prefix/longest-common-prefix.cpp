class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char med=strs[0][i];
            bool check=true;
            for(int j=0;j<n;j++){
                if(med!=strs[j][i]){
                    check=false;
                }
            }
            if(check){
                ans+=med;
            }
            else break;
        }
        return ans;
    }
};