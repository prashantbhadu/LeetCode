class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        if(s.empty()) return 0;
        int r=0;
        int e=0;
        int ans=INT_MIN;
        while(e<s.size()){
            mpp[s[e]-'0']++;
            while(mpp[s[e]-'0']>1){
                mpp[s[r]-'0']--;
                r++;
            }
            
            ans=max(ans,e-r+1);
            e++;
        }
        return ans;
    }
};