class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        stack<char>st;
        for(char c:num){
            while(!st.empty() && st.top()-'0'>c-'0' && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
                ans+=st.top();
                st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()&& ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        if(ans.size()==0) return "0"; 
        return ans;

    } 
};