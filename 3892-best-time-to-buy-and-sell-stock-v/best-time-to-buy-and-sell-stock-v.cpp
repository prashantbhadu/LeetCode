class Solution {
public:
    long long solve(int ind,int transtype, int n, vector<int>&prices, int k){
        if((k==0 || ind==n)&& transtype==0) return 0;
        if((k==0 || ind==n)&& transtype!=0) return -1e18;
        long long temp1=-1e18;
        long long temp2=-1e18;
        long long temp3=-1e18;
        if(transtype==0){
            temp1=-prices[ind]+solve(ind+1,1,n,prices,k); // bought the stock now i can sell it.
            temp2=prices[ind]+solve(ind+1,2,n,prices,k);  // sell the stock now i can buy it.
            temp3=solve(ind+1,0,n,prices,k); // did nothing move on.
        }
        else if(transtype==1){
            temp1=prices[ind]+solve(ind+1,0,n,prices,k-1);  // sold the stock now i can buy some stocks again.
            temp3=solve(ind+1, 1, n, prices,k); //did nothing
        }
        else{
            temp2=-prices[ind]+solve(ind+1,0,n,prices,k-1); // bought the stock now i can either sold it or buy other one.
            temp3= solve(ind+1,2,n,prices,k);
        }
        return max({temp1,temp2,temp3});
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long >>>dp(n+1,vector<vector<long long>>(3,vector<long long>(k+1,-1e18)));
        for(int i=0;i<=k;i++){
            dp[n][0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0][0]=0;
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int state=0;state<=2;state++){
                for(int rem=0;rem<=k;rem++){
                        long long temp1=-1e18;
                        long long temp2=-1e18;
                        long long temp3=-1e18;
                        if(state==0){
                            temp1=-prices[ind]+dp[ind+1][1][rem]; // bought the stock now i can sell it.
                            temp2=prices[ind]+dp[ind+1][2][rem];  // sell the stock now i can buy it.
                            temp3=dp[ind+1][0][rem]; // did nothing move on.
                        }
                        else if(state==1){
                            if(rem>0)
                                temp1=prices[ind]+dp[ind+1][0][rem-1];  // sold the stock now i can buy some stocks again.
                            temp3=dp[ind+1][1][rem]; //did nothing
                        }
                        else{
                            if(rem>0)
                                temp2=-prices[ind]+dp[ind+1][0][rem-1]; // bought the stock now i can either sold it or buy other one.
                            temp3= dp[ind+1][2][rem];
                        }
                        dp[ind][state][rem]=max({temp1,temp2,temp3});

                }
            }
        }
        return dp[0][0][k];
    }
};