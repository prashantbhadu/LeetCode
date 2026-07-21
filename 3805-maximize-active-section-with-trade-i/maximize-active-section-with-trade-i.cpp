class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ones++;
        }
        int ans=ones;
        // s='1'+ s + '1';
        int fzero;
        int n=s.size();
        int i=0;
        int lftzero=0;
        while(i<n && s[i]=='1'){
            i++;
        }
        while(i<n && s[i]=='0'){
            lftzero++;
            i++;
        }
        while(i<n){
            // read middle 1-block
            int c1=0;
            while(i<n && s[i]=='1'){
                c1++;
                i++;
            }
            if(c1==0) break;
            int rghtz=0;
            while(i<n && s[i]=='0'){
                rghtz++;
                i++;
            } 
            if(rghtz==0) break;
            ans=max(ans,ones+lftzero+rghtz);
            lftzero=rghtz;
        }
        return ans;
    }
};