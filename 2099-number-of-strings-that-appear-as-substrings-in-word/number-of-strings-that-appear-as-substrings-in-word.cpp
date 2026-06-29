class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        int m=patterns.size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(word.find(patterns[i])!= string::npos)ans++;
        }
        return ans;
        
    }
};