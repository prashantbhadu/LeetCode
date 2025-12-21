class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int ans=0;
        vector<bool>resolve(n-1,false);
        for(int col=0;col<m;col++){
            bool kenu=false;
            for(int row=0;row<n-1;row++){
                if(!resolve[row] && strs[row][col]>strs[row+1][col]){
                    kenu=true;
                    break;
                }
            }
            if(kenu) ans++;
            else{
                for(int row=0;row<n-1;row++){
                    if(strs[row][col]<strs[row+1][col]) resolve[row]=true;
                }
                }
        }
        return ans;
        
    }
};