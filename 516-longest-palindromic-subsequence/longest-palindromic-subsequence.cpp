class Solution {
public:
    int func(int start,int end,string&s){
        if(start>end) return 0;
        int pick=-1e9;
        if(s[start]==s[end]){
            if(start==end){
                return 1;
            }
            else{
                pick=2+func(start+1,end-1,s);
            }
        }
        int not_pick=max(func(start+1,end,s),func(start,end-1,s));
        return max(pick,not_pick);
    }
    int longestPalindromeSubseq(string s) {
        string k=s;
        reverse(k.begin(),k.end());
        int n=s.size();
       // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       vector<int>prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int>temp(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1]==k[j-1]){
                    temp[j]=1+prev[j-1];
                }
                else temp[j]=max(prev[j],temp[j-1]);
            }
            prev=temp;
        }
        return prev[n];
    }
};