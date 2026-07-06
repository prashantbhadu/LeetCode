class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ans=0;
        if(n==1)return 1;
        int i=0;
        int j=1;
        while(j<n && i<n ){
            if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1]){
                ans++;
                i=j;
                j++;
            }
            if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1]){
                j++;
                ans++;
            }
            else{
                i=j;
                j++;
            }
        }
        return n-ans;
    }
};