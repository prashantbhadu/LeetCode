class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]!=0 ||grid[r-1][c-1]!=0) return -1;
        queue<vector<int>>pq;
        vector<vector<int>>visit(r,vector<int>(c,0));
        int cnt=1;
        pq.push({0,0,cnt});
        visit[0][0]=1;
        
        while(!pq.empty()){
            auto temp=pq.front();
            pq.pop();
            int x=temp[0];
            int steps=temp[2];
            int y=temp[1];
            if(x==r-1 && y==c-1) return steps;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=r || ny>=c || visit[nx][ny] || grid[nx][ny]==1) continue;
                pq.push({nx,ny,steps+1});
                visit[nx][ny]=1;
            }
        }
        return -1;
    }
};