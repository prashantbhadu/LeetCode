class Solution {
public:
    vector<vector<int>>dp;
    int func(vector<int>&piles,int m,int ind){
        if(ind==piles.size()) return 0;
        int alice=-1e9;
        int curr=0; 
        if(dp[m][ind]!=-1) return dp[m][ind];
            for(int i=ind;i<ind+2*m && i<piles.size();i++){

                curr+=piles[i];
                alice = max(alice,curr-func(piles,max(m,i-ind+1),i+1));
            }

        return dp[m][ind]=alice;
        
    }
    int stoneGameII(vector<int>& piles) {
        dp.resize(100,vector<int>(piles.size(),-1));
        int diff=func(piles,1,0);
        int sum=0;
        for(auto it:piles) sum+=it;
        int a=(diff + sum) /2;
        return a;
    }
};