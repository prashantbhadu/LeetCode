class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            int s=0;
            int e=m-1;
            int md=s+(e-s)/2;
            while(s<=e){
                if(matrix[i][md]==target) return true;
                else if(matrix[i][md]>target) e=md-1;
                else s=md+1;
                md=s+(e-s)/2;
            }
        }
        return false;
    }
};