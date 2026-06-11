class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>store(n+2);
       
        vector<int>visited(n+2,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            store[u].push_back(v);
            store[v].push_back(u);
        }
        int level=0;
        queue<int>q;
        q.push(1);
        visited[1]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int val=q.front();
                q.pop();
                for(auto it:store[val]){
                    if(visited[it]!=1){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
            level++;
        }
        level--;
        long long ans = power(2, level - 1);
        return (int)ans;
    }
};