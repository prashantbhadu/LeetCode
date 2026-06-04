class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int kimo=INT_MAX;
        for(int i=0;i<n;i++){
            int tr=landStartTime[i]+landDuration[i];
            kimo=min(kimo,tr);
        }
        int lmao=INT_MAX;
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=kimo) lmao=min(lmao,waterDuration[i]);
            else{
                lmao=min(lmao,waterStartTime[i]-kimo + waterDuration[i]);
            }
        }
        kimo+=lmao;
        int kimo2=INT_MAX;
        for(int i=0;i<m;i++){
            int pr=waterStartTime[i]+waterDuration[i];
            kimo2=min(kimo2,pr);
        }
        int lmao2=INT_MAX;
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=kimo2) lmao2=min(lmao2,landDuration[i]);
            else{
                lmao2=min(lmao2,landStartTime[i]-kimo2+landDuration[i]);
            }
        }
        kimo2+=lmao2;
        int ans=min(kimo,kimo2);
        return ans;
    }
};