class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int>ans;
        if(n==0) return 1;
        while(n>1){
            int digit=n%2;
            if(digit==1) ans.push_back(0);
            else ans.push_back(1);
            n=n/2;
        }
        if(n==1) ans.push_back(0);
        
        int digit=0;
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=0){
                digit+=pow(2,i);
                cout<<digit<<" ";
            }
            
        }
        return digit;

    }
};