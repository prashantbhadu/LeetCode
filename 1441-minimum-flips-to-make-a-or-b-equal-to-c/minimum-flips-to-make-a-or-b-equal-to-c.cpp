class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=  __builtin_popcount((a|b)^c);
        int rslt = (a|b)^c;
        int lk= __builtin_popcount((a&b)&rslt);
        return cnt + lk;
    }
};