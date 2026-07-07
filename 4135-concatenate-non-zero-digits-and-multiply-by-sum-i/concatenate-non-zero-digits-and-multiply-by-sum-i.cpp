class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        n=stoi(s);
        long long ans=0;
        long long sum=0;
        while(n>0){
            int digit=n%10;
            if(digit==0){
                n=n/10;
                continue;
            }
            ans=digit + ans*10;
            sum+=digit;
            n=n/10;
        }
        
        return ans*sum;
    }
};