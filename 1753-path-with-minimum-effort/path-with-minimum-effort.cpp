class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<
        pair<int , pair<int,int>>,
        vector<pair<int , pair<int,int>>>,
        greater<pair<int , pair<int,int>>>
         > pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto temp=pq.top();
            int effort=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            pq.pop();
            // if(effort>dist[x][y]) continue;
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                    int neweffort=max(effort,abs(heights[x][y]-heights[new_x][new_y]));
                    if(neweffort<dist[new_x][new_y]){
                        dist[new_x][new_y]=neweffort;
                        pq.push({neweffort,{new_x,new_y}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
