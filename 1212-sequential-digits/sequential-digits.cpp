class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int>res;
       for(int i=1;i<=9;i++){
        int nums=i;
        for(int j=i+1;j<=9;j++){
            nums=nums*10 + j;
            if(nums>=low && nums<=high){
                res.push_back(nums);
            }
        }
       }
       sort(res.begin(),res.end());
        return res;
    }
};