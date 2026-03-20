class Solution {
public:
   int func(set<int> store) {
        vector<int> v(store.begin(), store.end());
        int diff = INT_MAX;

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                diff = min(diff, abs(v[i] - v[j]));
            }
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