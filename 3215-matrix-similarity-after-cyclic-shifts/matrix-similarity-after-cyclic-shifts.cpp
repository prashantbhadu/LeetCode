class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));
        int l=mat[0].size();
        int col=k%l;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
               if(i%2==0){
                if(mat[i][j]!=mat[i][(l+j-col)%l]) return false;
                }
               else{
                if(mat[i][j]!=mat[i][(l+j+col)%l]){
                    return false;
                }
               }

            }
        }
        
        return true;
    }
};