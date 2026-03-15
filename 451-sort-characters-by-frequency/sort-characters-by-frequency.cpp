class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto c:s){
            mpp[c]++;
        }
        set<pair<int,char>>store;
        for(auto& it:mpp){
            char k=it.first;
            int freq=it.second;
            store.insert({freq,k});
        }
        string ans="";
       for(auto& p:store){
        int freq=p.first;
        char k=p.second;
        ans.append(freq,k);
       }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};