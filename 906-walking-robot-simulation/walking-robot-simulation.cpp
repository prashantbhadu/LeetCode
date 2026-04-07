class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>blocked;
        for(auto&o: obstacles){
            blocked.insert({o[0],o[1]});
        }
        // vector<pair<int,int>>directions ={
        //     {0,1}, {1,0}, {0,-1}, {-1,0}
        // };
        int x=0;
        int y=0;
        int dir=0;
        int maxdist=0;
        for(int cmd:commands){
            if(cmd==-1) dir=(dir+1)%4;
            else if(cmd==-2) dir=(dir+3)%4;
            else{
                while(cmd--){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(blocked.count({nx,ny})) break;
                    x=nx;
                    y=ny;
                    maxdist=max(maxdist,x*x + y*y);
                }
            }
        }
        return maxdist;
    }
};