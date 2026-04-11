class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        vector<int>store(26,0);
        int maxlen=0;
        int check=0;
        int len=0;
        while(r<s.size()){
            store[s[r]-'A']++;
            check=max(check,store[s[r]-'A']);
            len=r-l+1;
            if(len-check>k){
                store[s[l]-'A']--;
                l++;
                len=r-l+1;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};