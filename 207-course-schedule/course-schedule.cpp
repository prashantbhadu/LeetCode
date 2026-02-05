class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
                int first=prerequisites[i][0];
                int sec=prerequisites[i][1];
                adj[sec].push_back(first);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        vector<int>top;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            top.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        if(top.size()==numCourses) return true;
        return false;
        
    }
};