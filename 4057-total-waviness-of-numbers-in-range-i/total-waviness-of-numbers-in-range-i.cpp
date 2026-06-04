class Solution {
public:
    int func(int x){
        string store=to_string(x);
        int n = store.size();
        if(n < 3) return 0;
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((store[i]-'0' > store[i - 1]-'0' && store[i]-'0' > store[i + 1]-'0') ||
                (store[i]-'0' < store[i - 1]-'0' && store[i]-'0' < store[i + 1]-'0')) {
                cnt++;
            }
        }

        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            count+=func(i);
        }
        return count;
    }
};