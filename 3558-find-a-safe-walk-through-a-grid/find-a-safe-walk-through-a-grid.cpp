class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[0][0]=1;
        if(grid[0][0]==1)health--;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({health,{0,0}});
        while(!pq.empty()){
            int sz=pq.size();
            for(int i=0;i<sz;i++){
                int heal=pq.top().first;
                int x=pq.top().second.first;
                int y=pq.top().second.second;
                pq.pop();
                if(x==n-1 && y==m-1 && heal>=1) return true;
                for(int j=0;j<4;j++){
                    int newx=x+dx[j];
                    int newy=y+dy[j];
                    if(newx<0 || newy<0 || newx>=n || newy>=m || visited[newx][newy])continue;
                    if(grid[newx][newy]==1){
                        pq.push({heal-1,{newx,newy}});
                        visited[newx][newy]=1;
                    }
                    else{
                        pq.push({heal,{newx,newy}});
                        visited[newx][newy]=1;
                    }
                }
            }
        }
        return false;
    }
};