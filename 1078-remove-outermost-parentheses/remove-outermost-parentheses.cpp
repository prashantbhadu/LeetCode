class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int check=0;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(check>0) ans+=s[i];
                check++;
            }
            else {
                check--;
                if(check>0) ans+=s[i];
            }
        }
        return ans;
    }
};