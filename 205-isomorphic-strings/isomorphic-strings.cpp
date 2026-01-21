class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp;
        unordered_map<char,char>mppp;
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i] ) return false;
            }
            if(mppp.find(t[i])!=mppp.end()){
                if(mppp[t[i]]!=s[i] ) return false;
            }
            mpp[s[i]]=t[i];
            mppp[t[i]]=s[i];

        }
        return true;
    }
};