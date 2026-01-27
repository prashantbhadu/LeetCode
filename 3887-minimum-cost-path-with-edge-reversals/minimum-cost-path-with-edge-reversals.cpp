class Solution {
public:
    int shortestPath(int n,vector<vector<pair<int,int>>>& adj) {
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});  //  1- wt, 2- ngbr
        int temp=0;
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [ngbr,wt]:adj[u]){
                if(dist[ngbr] > dist[u]+wt) {
                    dist[ngbr] = dist[u]+wt;
                    pq.push({dist[ngbr] , ngbr});
                }
            }
        }
        if(dist[n-1] == INT_MAX) return -1;
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i< edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        return shortestPath(n,adj);
    }
};