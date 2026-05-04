class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int row=matrix.size();
       for(int i=0;i<row;i++){
        for(int j=i;j<row;j++){
            swap(matrix[i][j],matrix[j][i]);

        }
       }
       int i=0;
       int k=row-1;
       while(i<row){
        for(int j=0;j<row/2;j++){
            swap(matrix[i][j],matrix[i][k]);
            k--;
        }
        k=row-1;
        i++;
       }
       

        
    }
};