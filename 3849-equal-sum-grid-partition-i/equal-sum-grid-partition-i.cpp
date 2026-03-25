class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int n=grid.size();
        long long sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
           
        }
       
        
        if(sum%2!=0) return false;
        long long target=sum/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[0].size();j++){
                target=target-grid[i][j];
            }
            if(target==0) return true;
        }
        target=sum/2;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                target=target-grid[j][i];
            }
            if(target==0) return true;
        }

        return false;

    }
};