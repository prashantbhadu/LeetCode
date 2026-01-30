class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=1;
                    visited[i][j]=1;
                }
            }
        }
        int way=0;
        
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                pair<int,int>pp=q.front();
                q.pop();
                int x=pp.first;
                int y=pp.second;

                isWater[x][y]=way;
                for(int l=0;l<4;l++){
                    int newx=x+dx[l];
                    int newy= y+dy[l];
                    if(newx>=0 && newy>=0 && newx<n && newy<m && visited[newx][newy]!=1){
                        q.push({newx,newy});
                        visited[newx][newy]=1;
                    }
                }
            }
            way++;
        }
        return isWater;
    }
};