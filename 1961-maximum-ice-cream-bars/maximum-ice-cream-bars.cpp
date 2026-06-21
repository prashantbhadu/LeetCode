class Solution {
public:
    
    int maxIceCream(vector<int>& costs, int coins) {
       
        int n=costs.size();
        //vector<vector<int>>dp(n+1,vector<int>(coins+1,0));
        sort(costs.begin(),costs.end());
        int maxprice=*max_element(costs.begin(),costs.end());
        vector<int>frq(maxprice+1,0);
        for(auto val:costs){
            frq[val]++;
        }
        int ans=0;
        
        for(int i=1;i<=maxprice;i++){
            if(frq[i]==0)continue;
            if(coins==0) break;
            int val=min(frq[i],(coins/i));
            coins=coins-val*i;
            ans+=val;
        }
        return ans;
    }
};