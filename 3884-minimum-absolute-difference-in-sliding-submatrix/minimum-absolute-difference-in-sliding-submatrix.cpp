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
       
        vector<vector<int>>ans;
        
        
        int r=grid.size();
        int col=grid[0].size();
        for(int i=0;i<(r-k)+1;i++){
            vector<int>result;
            for(int j=0;j<(col-k)+1;j++){
               set<int>store;
                for(int l=i;l<k+i;l++){
                    for(int m=j;m<k+j;m++){

                        store.insert(grid[l][m]);
                    }
                }
                
                int diff=func(store);
                diff==INT_MAX?result.push_back(0):result.push_back(diff);

            }
            ans.push_back(result);
        }
        return ans;
    }
};