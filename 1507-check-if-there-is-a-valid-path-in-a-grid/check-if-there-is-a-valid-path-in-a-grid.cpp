class Solution {
public:

    bool hasValidPath(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<pair<int,int>>>dirc(7);
        dirc[1]={{0,-1},{0,1}};
        dirc[2]={{-1,0},{1,0}};
        dirc[3]={{0,-1},{1,0}};
        dirc[4]={{0,1},{1,0}};
        dirc[5]={{0,-1},{-1,0}};
        dirc[6]={{0,1},{-1,0}};
        vector<vector<int>>visited(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==row-1 && c==col-1) return true;
            for(auto [dr,dc]:dirc[grid[r][c]]){
                int nr=r+dr;
                int nc=c+dc;
                if(nr<0 || nr>=row || nc<0 || nc>=col || visited[nr][nc]) continue;
                for(auto [bdr,bdc]: dirc[grid[nr][nc]]){
                    if(nr+bdr== r && nc+ bdc == c){
                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
};