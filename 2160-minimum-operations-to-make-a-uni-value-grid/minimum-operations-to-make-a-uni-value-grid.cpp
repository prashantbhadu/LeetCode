class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>store;
        int ev=0;
        int odd=0;
        int check=grid[0][0]%x;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                store.push_back(grid[i][j]);
                if( i+j>=1 && grid[i][j]%x!=check) return -1;
            }
        }
        sort(store.begin(),store.end());
        int n=store.size();
        int val=store[(n-1)/2];
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(val-store[i])/x;
        }
        return ans;
    }
};