class Solution {
public:

    bool check(int n,
               vector<vector<pair<int,int>>> &adj,
               vector<bool> &online,
               long long k,
               int limit)
    {
        vector<int> indegree(n,0);

        for(int u=0;u<n;u++)
        {
            for(auto &e:adj[u])
            {
                int v=e.first;
                int w=e.second;

                if(w<limit) continue;

                if(v!=n-1 && !online[v]) continue;

                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<long long> dist(n,LLONG_MAX);

        dist[0]=0;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto &e:adj[u])
            {
                int v=e.first;
                int w=e.second;

                if(w<limit) continue;

                if(v!=n-1 && !online[v]) continue;

                if(dist[u]!=LLONG_MAX)
                    dist[v]=min(dist[v],dist[u]+w);

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {

        int n=online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mx=0;

        for(auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            mx=max(mx,e[2]);
        }

        int low=0;
        int high=mx;

        int ans=-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(check(n,adj,online,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }

        return ans;
    }
};