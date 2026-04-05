class Solution {
public:
    bool judgeCircle(string moves) {
        int cntu=0;
        int cntd=0;
        int cntl=0;
        int cntr=0;
        for(char s:moves){
            if(s=='U')cntu++;
            else if(s=='D')cntd++;
            else if(s=='R')cntr++;
            else cntl++;
        }
        if(cntu==cntd && cntr==cntl) return true;
        return false;
    }
};