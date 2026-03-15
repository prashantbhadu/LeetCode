class Solution {
public:
    int func(int mid,int high,vector<vector<int>>& mat){
        int ans=INT_MIN;
        int ind=0;
        for(int i=0;i<mat.size();i++){
            if(mat[i][mid]>ans){
                ans=mat[i][mid];
                ind=i;
            }
        }
        return ind;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int s=0;
        int e=m-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int row=func(mid,e,mat);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(right>=mat[row][mid]) s=mid+1;
            else e=mid-1;
            mid=s+(e-mid)/2;
        }
        
        return {-1, -1}; 
    }
};