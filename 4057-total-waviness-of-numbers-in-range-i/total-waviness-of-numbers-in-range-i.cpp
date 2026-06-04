class Solution {
public:
    int func(vector<int>store){
        int n = store.size();
        if(n < 3) return 0;
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            if ((store[i] > store[i - 1] && store[i] > store[i + 1]) ||
                (store[i] < store[i - 1] && store[i] < store[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int count=0;
        while(num1<=num2){
            int val=num1;
            vector<int>store;
            while(val>0){
                int digit=val%10;
                store.push_back(digit);
                val/=10;
            }
            count+=func(store);
            num1++;
        }
        return count;
    }
};