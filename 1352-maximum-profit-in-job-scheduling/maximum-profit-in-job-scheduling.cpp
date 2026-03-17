class Solution {
public:
    int findNextJob(vector<vector<int>>&arr,int left, int target) {
        int right = arr.size()-1;
        int result=-1;
        while (left<= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid][0] >= target) {
                result = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return result;  // First job with start >= currentEnd
    }
    int solve(vector<vector<int>>&arr, int ind, vector<int>&dp){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int next=findNextJob(arr,ind+1,arr[ind][1]);
        int taken = arr[ind][2]+ solve(arr,next,dp);
        int nottaken = solve(arr,ind+1,dp);
        return dp[ind]=max(taken,nottaken); 
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<int>dp(n+1,-1);
        vector<vector<int>>arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i]; 
        }
        sort(arr.begin(),arr.end());
        return solve(arr,0,dp);

    }
};