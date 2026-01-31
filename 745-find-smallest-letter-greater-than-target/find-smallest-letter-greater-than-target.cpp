class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int goal=target-'a';
        char ans=letters[0];
        for(int i=0;i<letters.size();i++){
            if(letters[i]-'a'>goal){
                return letters[i];
            }
        }
        return letters[0];
    }
};