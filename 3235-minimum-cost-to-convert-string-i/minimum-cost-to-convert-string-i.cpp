class Solution {
public:
    void floydbarshell(vector<vector<int>>& adj) {
        for(int k = 0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j= 0;j < 26;j++) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> adj(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++) {
            adj[i][i] = 0;
        }
        for(int i = 0; i<original.size(); i++) {
            adj[original[i]-'a'][changed[i]-'a'] = min(adj[original[i]-'a'][changed[i]-'a'],cost[i]);
        }

        floydbarshell(adj);
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            ans+=adj[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};