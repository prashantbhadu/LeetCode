class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numCourses=graph.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};