class Solution {
public:
    int maxProduct(int n) {
        vector<int>store;
        while(n>0){
            int digit=n%10;
            store.push_back(digit);
            n=n/10;
        }
        sort(store.begin(),store.end());
        int k=store.size();
        return store[k-1]*store[k-2];
    }
};