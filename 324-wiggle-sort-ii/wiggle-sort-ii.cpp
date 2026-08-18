class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return ;
        vector<int>rev=nums;
        sort(rev.begin(),rev.end());
        int i=n-1;
        int j=0;
        int k=i/2 + 1;
        while(i>=0){
            if(i%2==1){
                nums[i]=rev[k];
                k++;
            }
            else{
                nums[i]=rev[j];
                j++;
            }
            i--;
        }
    }
};