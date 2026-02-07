class Solution {
public:
   
    int minimumDeletions(string s) {
        int bcount=0;
        int deletions=0;
        for(auto c:s){
            if(c=='b'){
                bcount++;
            }
            else{
                if(bcount>0){
                    deletions++;
                    bcount--;
                }
            }
        }
        return deletions;
    }
};