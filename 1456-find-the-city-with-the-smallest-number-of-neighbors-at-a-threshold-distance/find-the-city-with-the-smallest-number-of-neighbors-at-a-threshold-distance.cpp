class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int r=n;
        int c=n;
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        for(int i=0;i<n;i++){
            for(auto it:edges){
                dist[it[0]][it[1]]=it[2];
                dist[it[1]][it[0]]=it[2];
            }
        }
            for(int j=0;j<c;j++){
                 dist[j][j]=0;
            }
        for(int k=0;k<n;k++){
            for(int i=0;i<c;i++){
                for(int j=0;j<c;j++){
                    if( dist[i][k]==1e9 || dist[k][j]==1e9) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cntcity=n;
        int cityno=-1;
        for(int i=0;i<r;i++){
            int cnt=0;
            for(int j=0;j<c;j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cntcity){
                cntcity=cnt;
                cityno=i;
            }
        }
        return cityno;
    }
};