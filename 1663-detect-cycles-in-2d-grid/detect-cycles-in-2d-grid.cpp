class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    struct Node {
    int x;
    int y;
    int px;
    int py;
   };
    bool bfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[row][col]=1;
        queue<Node>q;
        q.push({row,col,-1,-1});
        while(!q.empty()){
             Node curr=q.front();
             int x=curr.x;
             int y=curr.y;
             int px=curr.px;
             int py=curr.py;
             q.pop();
             for(int k=0;k<4;k++){
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()) continue;
                if(grid[nx][ny]!=grid[x][y]) continue;
                if( nx==px && ny==py) continue;
                if(!visited[nx][ny]){
                    visited[nx][ny]=1;
                    q.push({nx,ny,x,y});
                }
                else return true;
             }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j]){
                    if(bfs(i,j,grid,visited)) return true;
                }
            }
        }
        return false;
    }
};