class Solution {
public:
    vector<int>dp;
    long long func(vector<int>&stoneValue,int ind){
        if(ind>=stoneValue.size()) return 0;
        long long  alice=LONG_MIN;
        long long curr=0;
        int cnt=0;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind; i<ind+3 && i<stoneValue.size();i++){
            cnt++;
            curr+=stoneValue[i];
            alice=max(alice,curr-func(stoneValue,ind+cnt));
        }
        return dp[ind]=alice;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size()+1,-1);
        long long diff=func(stoneValue,0);

        if(diff==0) return "Tie";
        else if(diff>0) return "Alice";
        else return "Bob";
    }
};