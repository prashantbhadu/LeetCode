class Solution {
public:
    int mod=1000000007;
    int func(int zero, int one, int limit, int last,int count,vector<vector<vector<vector<int>>>>&dp){
        if(zero==0 && one==0) return 1;
        int ans=0;
        if(last!=-1 && dp[zero][one][last][count]!=-1) return dp[zero][one][last][count];
        if(zero>0){
            if(last==0){
                if(count<limit){
                    ans+=func(zero-1,one,limit,0,count+1,dp);
                }
            }
            else{
                ans+=func(zero-1,one,limit,0,1,dp);
            }
        }
        if(one>0){
            if(last==1){
                if(count<limit){
                    ans+=func(zero,one-1,limit,1,count+1,dp);
                }
            }
            else{
                ans+=func(zero,one-1,limit,1,1,dp);
            }
        }
        ans %=mod;

        if(last != -1)
            dp[zero][one][last][count] = ans;

        return ans;

    }
    int numberOfStableArrays(int zero, int one, int limit) {
         vector<vector<vector<vector<int>>>> dp(
            zero+1,
            vector<vector<vector<int>>>(
                one+1,
                vector<vector<int>>(2, vector<int>(limit+1, -1))
            )
        );

        return func(zero,one,limit,-1,0,dp);
        
    }
};