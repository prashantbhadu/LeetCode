class Solution {
public:
    int mod= 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xora=0;
        ll xorb=0;
        for(ll i=50;i>=n;i--){
            bool acnt=((1ll<<i)&a)>0;
            bool bcnt = ((1ll<<i)&b)>0;
            if(acnt==true)
                xora=(xora^(1ll<<i));
            if(bcnt)
                xorb=(xorb^(1ll<<i));
        }
        for(ll i=n-1;i>=0;i--){
            bool acnt=((1ll<<i)&a)>0;
            bool bcnt = ((1ll<<i)&b)>0;
            if(acnt==bcnt){
                xorb = xorb^(1ll<<i);
                xora = xora^(1ll<<i);
                continue;
            }
            if(xora>xorb){
                xorb=xorb^(1ll<<i);
            }
            else xora=xora^(1ll<<i);
        }
        xora=xora%mod;
        xorb=xorb%mod;
        return (xora*xorb)%mod;
    }
};