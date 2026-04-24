class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int r=0;
        int l=0;
        for(char ch:moves){
            if(ch=='R') r++;
            else if(ch=='L')l++;
        }
        if(r==0 && l==0) return n;
        else if(r>l) return n-2*l;
        else return n-2*r;
        
    }
};