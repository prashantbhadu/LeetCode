class Solution {
public:
    int smallestNumber(int n, int t) {
        int rst=1;
        if(n%10==0) return n;
        for(int i=n;i<=n+9;i++){
            rst=i;
            int ans=1;
            int val=i;
            while(val>0){
                int digit=val%10;
                ans*=digit;
                val=val/10;
            }
            if(ans%t==0){
                break;
            }
        }
       return rst;

    }
};