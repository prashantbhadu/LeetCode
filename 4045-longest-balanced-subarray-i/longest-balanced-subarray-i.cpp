class Solution {
public:
    int longestBalanced(vector<int>& nums) {
       
        int len=0;
       for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mpp;
             int oddcnt=0;
             int evncnt=0;
            for(int j=i;j<nums.size();j++){
                if(mpp.find(nums[j])==mpp.end()){
                    mpp[nums[j]]=1;
                    if(nums[j]%2==0)evncnt++;
                    else oddcnt++;
                }
                if(evncnt==oddcnt) len=max(len,j-i+1);
               
            }
       }
       return len;
    }
};