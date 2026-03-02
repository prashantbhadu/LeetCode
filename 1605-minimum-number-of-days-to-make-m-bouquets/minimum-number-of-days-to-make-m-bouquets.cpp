class Solution {
public:
    int func(int mid, int k,vector<int>&bloomDay){
        int ans=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                cnt++;
                if(cnt==k){
                    ans++;
                    cnt=0;
                }
               
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=*min_element(bloomDay.begin(),bloomDay.end());
        int last=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=start+(last-start)/2;
        int reslt=-1;
        while(start<=last){
            if(func(mid,k,bloomDay)>=m){
                reslt=mid;
                last=mid-1;
            }
            else if(func(mid,k,bloomDay)<m) start=mid+1;
            mid=start+(last-start)/2;
        }
        return reslt;
    }
};