class Solution {
public:
    bool check(vector<int>&arr,int start,vector<int>&vis){
        if(start>=arr.size()|| start<0) return false;
        if(arr[start]==0) return true;
        if(vis[start]==true) return false;
         vis[start]=true;
        return check(arr,start+arr[start],vis) || check(arr,start-arr[start],vis); 
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return check(arr,start,vis);

    }
};