class Solution {
public:
    int  check(int x){
        int cnt=0;
        while(x>0){
            cnt++;
            x=x/10;
        }
        return cnt;

    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>store;
        int ans=0;
        int m=arr1.size();
        int n=arr2.size();
        for(auto num:arr1){
            int x=num;
            while(x>0){
                store.insert(x);
                x=x/10;
            }
        }
        for(auto num:arr2){
            int x=num;
            int len=check(x);
            while(x>0){
                if(store.count(x)){
                    ans=max(ans,len);
                }
                len--;
                x=x/10;
            }
        }
        return ans;
    }
};