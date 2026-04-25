class Solution {
public:
    int mirrorDistance(int n) {
        int ans=0;
        int temp=n;
        while(n){
            ans=ans*10 + n%10;
            n=n/10;
        }
        return abs(temp-ans);
    }
};