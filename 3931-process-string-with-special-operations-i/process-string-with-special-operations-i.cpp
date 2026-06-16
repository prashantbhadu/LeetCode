class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char it: s){
            if(it=='*' && result.empty() )continue;
            else if(it=='*'){
                result.pop_back();
            }
            else if(it=='%') reverse(result.begin(),result.end());
            else if(it=='#'){
                result+=result;
            }
            else{
                result+=it;
            }
        }
        return result;
    }
};