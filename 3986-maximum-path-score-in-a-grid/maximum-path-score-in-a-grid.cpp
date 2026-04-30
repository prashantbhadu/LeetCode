class Solution {
public:
    int func(int i, int j, int cost, vector<vector<int>>& grid, int k, 
             vector<vector<vector<int>>>& dp) {
        
        // Bug 1 fixed: OOB before dp lookup
        if (i >= grid.size() || j >= grid[0].size()) return -1e9;

        if (i == grid.size()-1 && j == grid[0].size()-1) {
            int finalCost = cost + (grid[i][j] != 0 ? 1 : 0);
            return finalCost <= k ? grid[i][j] : (int)-1e9;
        }

        if (dp[i][j][cost] != -1) return dp[i][j][cost];

        int newCost = cost + (grid[i][j] != 0 ? 1 : 0);
        if (newCost > k) return dp[i][j][cost] = -1e9;

        int right = func(i, j+1, newCost, grid, k, dp);
        int down  = func(i+1, j, newCost, grid, k, dp);

        // Bug 3 fixed: store in all cases
        if (right == (int)-1e9 && down == (int)-1e9) 
            return dp[i][j][cost] = -1e9;
        if (right == (int)-1e9) 
            return dp[i][j][cost] = grid[i][j] + down;
        if (down == (int)-1e9)  
            return dp[i][j][cost] = grid[i][j] + right;
        return dp[i][j][cost] = grid[i][j] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        // Bug 2 fixed: k+1 size
        vector<vector<vector<int>>> dp(
            grid.size(), vector<vector<int>>(
                grid[0].size(), vector<int>(k+1, -1)));

        // Bug 4 fixed: directly use return value
        int ans = func(0, 0, 0, grid, k, dp);
        return ans == (int)-1e9 ? -1 : ans;
    }
};