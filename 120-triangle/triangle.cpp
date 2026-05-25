class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>prev(m,0);
        for(int i=0;i<m;i++){
            prev[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(m,0);
            for(int j=i;j>=0;j--){
                int same=triangle[i][j] + prev[j];
                int diag=triangle[i][j]+prev[j+1];
                temp[j]=min(same,diag);
            }
            prev=temp;
        }
        return prev[0];
    }
};