class Solution {
public:
    void func(vector<vector<char>>&mat,int ind,vector<int>&sum){
        vector<int>store;
        for(int i=ind;i<=ind;i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='0') sum[j]=0;
                else{
                    sum[j]+=mat[i][j]-'0';
                }
            }
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
        stack<int>st;
        vector<int>sum(m,0);
        for(int k=0;k<n;k++){
            func(matrix,k,sum);
            for(int i=0;i<m;i++){
            while(!st.empty() && sum[st.top()]>sum[i]){
                int element=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                maxarea=max(maxarea,sum[element]*(nse-pse-1));
            }
            st.push(i);
        }
            while(!st.empty()){
                int element=st.top();
                st.pop();
                int nse=m;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,sum[element]*(nse-pse-1));
            }
        }
        
        return maxarea;
    }
};