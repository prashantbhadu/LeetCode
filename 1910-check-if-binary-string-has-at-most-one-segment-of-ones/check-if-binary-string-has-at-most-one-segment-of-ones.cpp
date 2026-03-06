class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        if(n==1) return true;
        for(int i=1;i<n;i++){
            cout<<s[i]<<" ";
            if( s[i]=='1' && s[i-1]=='0'){
                return false;
            }
        }
        return true;
    }
};