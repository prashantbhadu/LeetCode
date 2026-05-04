class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,pair<int,int>>>cell;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cell.push_back({grid[i][j],{i,j}});
            }
        }
        sort(cell.begin(),cell.end());
        vector<vector<int>>visit(n,vector<int>(n,0));
        DisjointSet dsu(n*n);
        for(auto&cells:cell){
            int h=cells.first;
            int i=cells.second.first;
            int j=cells.second.second;
            visit[i][j]=1;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x<0 || y<0 || x>=n || y>=n ||!visit[x][y]) continue;
                int node=i*n+j;
                int newnode=x*n+y;
                dsu.unionBySize(node,newnode);
            }
            if(dsu.findUPar(0)==dsu.findUPar(n*n-1)) return h;
        }
        return -1;
    }

};