class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        int n=s.size();
        char ch;
        bool check=false;
        if(n%2!=0) {
            ch=s[(n/2)];
            check=true;
        }
        for(int i=0;i<n/2;i++){
            ans+=s[i];
        }
        sort(ans.begin(),ans.end());
        string temp=ans;
        reverse(temp.begin(),temp.end());
        if(check){
            return ans=ans+ch+temp;
        }
        else return ans+temp;

    }
};