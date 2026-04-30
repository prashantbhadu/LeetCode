class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0}; 
    void func(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&visited){
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
           
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || visited[nx][ny]==1 || grid[nx][ny]=='0') continue;
                else{
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    func(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};