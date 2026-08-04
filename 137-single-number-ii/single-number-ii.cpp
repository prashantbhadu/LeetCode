class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<=31;i++){
            int temp=(1<<i);
            int cnto=0;
            int cntz=0;
            for(auto num:nums){
                if((temp&num)==0)cntz++;
                else cnto++;
            }
            if(cnto%3==1){
                result = (result|temp);
            }
        }
        return result;
    }
};