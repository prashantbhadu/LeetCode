class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int cnt1=0;
        int cnt2=0;
        int mini1=0;
        int mini2=0;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i+1]-hBars[i]==1)cnt1++;
            else{
                cnt1=0;
            }
            mini1=max(mini1,cnt1);

        }
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i+1]-vBars[i]==1)cnt2++;
            else{
                
                cnt2=0;
            }
            mini2=max(mini2,cnt2);

        }
        int ans=min(mini1+2,mini2+2);
        return ans*ans;
    }
};