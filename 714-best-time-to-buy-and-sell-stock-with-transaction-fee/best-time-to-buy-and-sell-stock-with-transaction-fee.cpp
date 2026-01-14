class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>after(2,0);
        vector<int>curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=-1e9;
                if(buy==1){
                    curr[buy]=max(-prices[ind]+after[0],after[1]);
                }
                else{
                    curr[buy]=max(prices[ind]+after[1]-fee,after[0]);
                }

                
            }
            after=curr;
        }
        return after[1];

    }
};