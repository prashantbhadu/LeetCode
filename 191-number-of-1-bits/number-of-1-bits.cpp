class Solution {
public:
    int count=1;
    void solve(int n){
        while(n>1){
            if(n%2==1){
                count++;
            }
            n=n/2;
        }
    }
    int hammingWeight(int n) {
      
        solve(n);
        return count;
    }
};