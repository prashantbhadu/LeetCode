class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        vector<vector<char>>mat(rows,vector<char>(col));
        int ind=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                mat[i][j]=encodedText[ind++];
            }
        }
        string result="";
        for(int startcol=0;startcol<col;startcol++){
            int i=0, j=startcol;
            while(i<rows && j<col){
                result+=mat[i][j];
                i++;
                j++;
            }
        }
        while(!result.empty() && result.back()==' ') result.pop_back();
        return result;

    }
};