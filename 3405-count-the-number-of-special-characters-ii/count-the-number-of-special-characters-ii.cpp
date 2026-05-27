class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>upper;
        map<char,int>lower;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                lower[word[i]]=i;
            }
            else{
                if(!upper.count(word[i])){
                    upper[word[i]]=i;
                }
            }
        }
        int cnt=0;
        for(auto chari:lower){
           char upperChar = chari.first - 32;

            if (upper.count(upperChar)) {
                if (upper[upperChar] > chari.second) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};