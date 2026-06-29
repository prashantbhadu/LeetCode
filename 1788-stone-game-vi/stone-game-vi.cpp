class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
       priority_queue<pair<int,pair<int,int>>>pq;
       for(int i=0;i<bobValues.size();i++){
        int mx=aliceValues[i]+bobValues[i];
        pq.push({mx,{bobValues[i],aliceValues[i]}});
       }
       int i=0;
       int als=0;
       int bobs=0;
       while(!pq.empty()){
        int alice=pq.top().second.second;
        int bob=pq.top().second.first;
        pq.pop();
        if(i%2==0){
            als+=alice;
        }
        else bobs+=bob;
        i++;
       }
       if(als>bobs) return 1;
       else if(als==bobs) return 0;
       else return -1;
    }
};