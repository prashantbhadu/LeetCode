class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int from=flights[i][0];
            int to=flights[i][1];
            int cost=flights[i][2];
            adj[from].push_back({to,cost});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<vector<int>>st;
        st.push({0,src,0});
        while(!st.empty()){
            int sz=st.size();
            auto pr=st.front();
            int cost=pr[0];
            int source=pr[1];
            int steps=pr[2];
            st.pop();
            if(steps>k) break;
            for(auto it:adj[source]){
                    int kharcha=it.second;
                    int tar=it.first;
                    int wt=kharcha+cost;
                    if(wt<dist[tar]){
                        st.push({wt,tar,steps+1});
                        dist[tar]=wt;
                    }
            }
        }
        return dist[dst]!=INT_MAX?dist[dst]:-1;

    }
};