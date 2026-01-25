class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&arr){
        if(i==n-1) return arr[i][j];
        int down=1e9;
        int right=1e9;
        down=arr[i][j]+solve(i+1,j,n,arr);
        if(j<=i+1){
            right=arr[i][j]+solve(i+1,j+1,n,arr);
        }
        return min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j] + dp[i+1][j];
                int diag=triangle[i][j] + dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};