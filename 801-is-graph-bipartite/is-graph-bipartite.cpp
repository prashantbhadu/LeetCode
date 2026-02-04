class Solution {
public:
    bool dfs(int ind,int rang,vector<int>&color,vector<vector<int>>&graph){
        color[ind]=rang;
        for(auto it:graph[ind]){
            if(color[it]== -1){
                if(dfs(it,!rang,color,graph)==false) return false;
            }
            else if(color[it]==rang) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size());
        for(int i=0;i<graph.size();i++){
            color[i]=-1;
        }
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};