class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>upper;
        unordered_set<char>lower;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                lower.insert(word[i]);
            }
            else{
                upper.insert(word[i]);
            }
        }
        int cnt=0;
        for(auto chari:lower){
            if(upper.count(chari-32))cnt++;
        }
        return cnt;
    }
};