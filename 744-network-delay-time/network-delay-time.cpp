class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u-1].push_back({w,v-1});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>store(n,1e9);
        pq.push({0,k-1});
        store[k-1] = 0;
        while(!pq.empty()){
            auto pr=pq.top();
            int wtime=pr.first;
            int node=pr.second;
            pq.pop();
            for(auto it:adj[node]){
                int nbr=it.second;
                int nbr_wt=it.first;
                int new_wt=wtime+nbr_wt;
                if(new_wt<store[nbr]){
                    pq.push({new_wt,nbr});
                    store[nbr]=new_wt;
                }
            }
        }
        int ans=-1e9;
        for(int i=0;i<store.size();i++){
            if(store[i]==1e9) return -1;
            else if(ans<store[i]){
                ans = store[i];
            }
        }
        return ans;
    }
};