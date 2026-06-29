class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]),i});
        }
        vector<int>ans;
        while(k>0){
            int ind=pq.top().second;
            pq.pop();
            ans.push_back(arr[ind]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};