class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<matrix[0].size();i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int down=matrix[i][j]+dp[i-1][j];
                int ld=1e9;
                if(j>0) ld=matrix[i][j]+dp[i-1][j-1];
                int rd=1e9;
                if(j<matrix[0].size()-1) rd=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min({down,ld,rd});
            }
        }
        int minSum=1e9;
        for(int i=m-1;i>=0;i--){
            minSum=min(minSum,dp[n-1][i]);
        }
        return minSum;
    }
};