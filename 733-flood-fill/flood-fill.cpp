class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visit[sr][sc]=1;
        int org_color=image[sr][sc];
        if(org_color==color) return image;
        image[sr][sc]=color;
        while(!q.empty()){
            pair<int,int>val=q.front();
            q.pop();
            int x=val.first;
            int y=val.second;
            for(int i=0;i<4;i++){
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(new_x>=n || new_x<0 || new_y>=m || new_y<0 || image[new_x][new_y]!=org_color) continue;
                else{
                    if(!visit[new_x][new_y]){
                        image[new_x][new_y]=color;
                        q.push({new_x,new_y});
                        visit[new_x][new_y]=1;
                    }
                }
            }
        }
        return image;
    }
};