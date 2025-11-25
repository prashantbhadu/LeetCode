class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        if(k==2 || k==5) return -1;
        int rem=0;
        int count=0;
        for(int i=0;i<k;i++){
            rem=(rem*10 +1)%k;
            count++;
            if(rem==0){
                return count;
            }
        }
        return -1;
    }
};