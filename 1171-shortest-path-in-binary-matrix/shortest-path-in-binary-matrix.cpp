class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        pq.push({0,0});
        distance[0][0]=1;
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            int kd=p.first;
            int dn=p.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0){
                    if(distance[kd][dn]+1<distance[x][y]){
                        distance[x][y]=distance[kd][dn]+1;
                        pq.push({x,y});
                    }
                }
            }
        }  
        if(distance[n-1][m-1]==1e9) return -1;
        return distance[n-1][m-1];             

    }
};