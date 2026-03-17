class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int cnt=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            sort(matrix[i].rbegin(),matrix[i].rend());
            for(int j=0;j<m;j++){
                cnt=max(cnt,matrix[i][j]*(j+1));
            }
        }
        return cnt;

    }

};