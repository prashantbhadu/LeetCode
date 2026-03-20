class Solution {
public:
   int func(set<int> store) {
        if (store.size() < 2) return 0; // or INT_MAX depending on need

        int diff = INT_MAX;

        auto it = store.begin();
        auto prev = it;
        ++it;

        while (it != store.end()) {
            diff = min(diff, abs(*it - *prev));
            prev = it;
            ++it;
        }

        return diff;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
       
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                vector<int> temp;

                for(int r = i;r<i+k;r++){
                    for(int c = j;c<j+k;c++){
                        temp.push_back(grid[r][c]);
                    }
                }
                sort(begin(temp),end(temp));
                int diff = INT_MAX;
                for(int x=0;x<temp.size()-1;x++){
                    if(temp[x]!=temp[x+1]){
                        diff = min(diff,abs(temp[x]-temp[x+1]));
                    }
                }
                if(diff==INT_MAX) ans[i][j]=0;
                else ans[i][j]=diff;
            }
        }
        return ans;
    }
};