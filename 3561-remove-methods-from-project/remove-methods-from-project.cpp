class Solution {
public:
   void dfs(int k,vector<int>&sus,vector<vector<int>>&adj){
    sus[k]=1;
    for(auto v:adj[k]){
        if(!sus[v]) dfs(v,sus,adj);
    }
   }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
       vector<int>sus(n,0);
       vector<vector<int>>adj(n);
       for(auto &nodes:invocations){
        int first=nodes[0];
        int sec=nodes[1];
        adj[first].push_back(sec);
       }
       dfs(k,sus,adj);
        vector<int>ans;
       for(int i=0;i<n;i++){
        for(auto v:adj[i]){
            if(sus[i]==0 && sus[v]==1){
                for(int j=0;j<n;j++){
                    ans.push_back(j);
                }
                return ans;
            }
        }
       }
       for(int i=0;i<n;i++){
        if(sus[i]==0) ans.push_back(i);
       }
       return ans;
    }
};