class Solution {
public:
    int solve(int i, int j, string& word1, string& word2){
        if(i<0 && j<0){
            return 0;
        }
        if(i<0 && j>=0) return j+1;
        if(i>=0 && j<0){
            return i+1;
        }
        if(word1[i]==word2[j]){
            return solve(i-1,j-1,word1,word2);
        }
        return min({1+solve(i-1,j,word1,word2), 1+solve(i-1,j-1,word1,word2), 1+solve(i,j-1,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>prev(m+1,0);
        vector<int>cur(m+1,0);

        for(int j=1;j<=m;j++){
            prev[j]=j;
        }
        // for(int i=1;i<=n;i++){
        //     dp[i][0]=i;
        // }
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    cur[j]=prev[j-1];
                }
                else{
                    cur[j]=min({1+prev[j],1+prev[j-1],1+cur[j-1]});
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};