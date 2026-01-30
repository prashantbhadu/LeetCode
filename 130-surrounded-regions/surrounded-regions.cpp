class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                } else if (j == 0 || j == m - 1) {
                   if (board[i][j] == 'O' ) {
                        q.push({i, j});
                        visited[i][j] = 1;
                   }
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                pair<int,int>pp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=pp.first + dx[i];
                    int y=pp.second + dy[i];
                    if(x>=0 && x<n && y>=0 && y<m && visited[x][y]!=1){
                        if(board[x][y]=='O'){
                            q.push({x,y});
                            visited[x][y]=1;
                        }
                    }
                }
            }
        }
        for(int  i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};