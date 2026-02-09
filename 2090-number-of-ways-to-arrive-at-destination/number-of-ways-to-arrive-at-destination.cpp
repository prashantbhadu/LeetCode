class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=1000000007;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int from=roads[i][0];
            int to=roads[i][1];
            int time=roads[i][2];
            adj[from].push_back({to,time});
            adj[to].push_back({from,time});
        }
        vector<long long>dist(n,1e18);
        vector<long long>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto pr=pq.top();
            long long wt=pr.first;
            int node=pr.second;
            pq.pop();
            if(wt>dist[node]) continue;
            for(auto it:adj[node]){
                int nbr=it.first;
                long long newwt=it.second+wt;
                if(newwt<dist[nbr]){
                    dist[nbr]=newwt;
                    ways[nbr]=ways[node];
                    pq.push({newwt,nbr});
                }
                else if(newwt==dist[nbr]){
                    ways[nbr]=(ways[nbr]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};