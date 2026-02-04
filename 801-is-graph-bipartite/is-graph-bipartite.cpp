class Solution {
public:
    bool dfs(int ind,vector<int>&visited,vector<int>&temp,vector<vector<int>>&graph){
        visited[ind]=1;
        queue<pair<int,int>>q;
        q.push({ind,-1});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>p=q.front();
                q.pop();
                int node=p.first;
                int parent=p.second;
                for(auto it:graph[node]){
                    if(!visited[it]){
                        q.push({it,node});
                        visited[it]=1;
                        temp[it]=temp[node]+1;
                    }
                    else if(parent!=it){
                        int len=abs(temp[it]-temp[node])+1;
                        if(len%2!=0) return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        vector<int>temp(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                if(dfs(i,visited,temp,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};