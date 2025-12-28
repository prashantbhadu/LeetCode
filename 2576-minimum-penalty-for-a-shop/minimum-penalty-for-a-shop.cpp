class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') penalty++;
        }
        int minpenalty=penalty;
        int ans=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') penalty--;
            else{
                penalty++;
            }
            if(minpenalty>penalty){
                minpenalty=penalty;
                ans=i+1;
            }
        }
        return ans;
    }
};