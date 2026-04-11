class Solution {
public:
    int numberOfSubstrings(string s) {
        int r=0;
        int l=0;
        int hash[3]={0};
        int ans=0;
        while(r<s.size()){
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                ans=ans+ (s.size()-r);
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};