class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n,1e9);
        vector<vector<pair<int,int>>>adj(n);
        for(auto nodes:times){
            int from=nodes[0];
            int to=nodes[1];
            int time=nodes[2];
            adj[from-1].push_back({to-1,time});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            pair<int,int>temp=pq.top();
            pq.pop();
            int time=temp.first;
            int node=temp.second;
            for(auto nbr:adj[node]){
                int newt=time+nbr.second;
                int newn=nbr.first;
                if(newt<dist[newn]){
                    dist[newn]=newt;
                    pq.push({newt,newn});
                    
                }
            }
        }
        int ans=-1e9;
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) return -1;
            else if(ans<dist[i]){
                ans = dist[i];
            }
        }
        return ans;
    }
};