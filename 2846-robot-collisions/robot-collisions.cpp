class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        if(n==1) return {healths[0]};
        vector<vector<int>> store;

        for(int i = 0; i < n; i++){
            store.push_back({positions[i], healths[i], directions[i],i});
        }
        sort(store.begin(),store.end());
        stack<int>st;
        for(int i=0;i<n;i++){
            if(store[i][2]=='R') st.push(i);
            else{
                while(!st.empty() && store[i][1]>0){
                    int j=st.top();
                    if(store[j][1]>store[i][1]){
                        store[j][1]--;
                        store[i][1]=0;
                    }
                    else if(store[j][1]<store[i][1]){
                        store[i][1]--;
                        store[j][1]=0;
                        st.pop();
                    }
                    else{
                        store[j][1]=0;
                        store[i][1]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int>ansindex(n,0);
        for(int i=0;i<n;i++){
            if(store[i][1]>0){
                ansindex[store[i][3]]=store[i][1];
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ansindex[i]>0){
                ans.push_back(ansindex[i]);
            }
        }
        return ans;

        
    }
};