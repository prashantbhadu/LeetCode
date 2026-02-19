class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans=0;
        vector<int>contones(n,0);
        if(s[0]=='1') contones[0]=1;
        for(int i=1;i<n;i++){
            contones[i]=contones[i-1]+(s[i]=='1'?1:0);
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=contones[j] -(i-1>=0?contones[i-1]:0);
                int zeroes=(j-i+1)-ones;
                if(zeroes*zeroes>ones){
                    int wastind=(zeroes*zeroes)-ones;
                    j+=wastind-1;
                }
                else if(zeroes*zeroes==ones){
                    ans+=1;
                }
                else{
                    ans+=1;
                    int k=sqrt(ones)-zeroes;
                    int next=j+k;
                    if(next>=n){
                        ans+=(n-j-1);
                        break;
                    }
                    else{
                        ans+=k;
                    }
                    j=next;
                }
            }
        }
        return ans;
    }
};
