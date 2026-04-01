class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=st.top();
            st.pop();
           int  nse=heights.size();
           int  pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,heights[element]*(nse-pse-1));

        }
        return maxarea;

    }
};