class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto it:words){
            int sum=0;
            for(int i=0;i<it.size();i++){
                int val=it[i]-'a';
                sum+=weights[val];
            }
            sum=sum%26;
            sum=25-sum;
            char ch='a'+sum;
            ans+=ch;
        }
        return ans;
    }
};