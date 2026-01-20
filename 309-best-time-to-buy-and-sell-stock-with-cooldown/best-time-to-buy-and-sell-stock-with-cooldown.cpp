class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        vector<int>cur(2,0);
        vector<int>forw(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit=-1e9;
                int not_profit=-1e9;
                if(j==1){
                    profit=-prices[i]+prev[0];
                    not_profit=prev[1];
                }
                else{
                    
                    profit=prices[i]+forw[1];
                    not_profit=prev[0];
                }
                cur[j]=max(profit,not_profit);
            }
            forw=prev;
            prev=cur;
            
        }
        return prev[1];
        
    }
};