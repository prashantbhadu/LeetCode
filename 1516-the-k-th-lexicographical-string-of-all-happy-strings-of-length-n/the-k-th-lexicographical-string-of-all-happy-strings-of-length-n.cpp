class Solution {
public:
    string func(string&s,int n,int&k ){
        if(s.size()==n){
            k--;
            if(k==0) return s;
            return "";

        }
        for(char i='a';i<='c';i++){
            if(s.empty() || s.back()!=i ){
               s.push_back(i);  // push_back expects a char, works directly
                string store_s=func(s,n,k);
                if(store_s!="") return store_s;
                s.pop_back();
                
            }
        }
        return "";
    }
    string getHappyString(int n, int k) {
        string s="";
        if(3*pow(2,n-1)<k) return "";
        vector<string>ans;
        return func(s,n,k);
        
    }
};