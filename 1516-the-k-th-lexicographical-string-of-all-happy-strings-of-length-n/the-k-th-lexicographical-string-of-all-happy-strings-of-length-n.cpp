class Solution {
public:
    void func(string&s,int n,vector<string>&ans){
        if(s.size()==n){
            ans.push_back(s);
            return ;

        }
        for(char i='a';i<='c';i++){
            if(s.empty() || s.back()!=i ){
               s.push_back(i);  // push_back expects a char, works directly
                func(s,n,ans);
                s.pop_back();
                
            }
        }
        return ;
    }
    string getHappyString(int n, int k) {
        string s="";
        vector<string>ans;
        func(s,n,ans);
        if(ans.size()>=k) return ans[k-1];
        else return "";
    }
};