class Solution {
public:
   int mint[6]={1,2,4,8,16,32};
   int hr[4]={1,2,4,8};
   void solve(int tar,int count,int mind, int hind,int msum, int hsum,vector<string>&ans){
    if(count==tar){
        if(hsum<12 && msum<60){
            string s=to_string(hsum)+ ":";
            if(msum<10) s+="0";
            s+=to_string(msum);
            ans.push_back(s);
        }
        return;
        
    }
    if(mind>=6 && hind>=4) return;
    if(mind<6){
        if(msum+mint[mind]<60){
            solve(tar,count+1,mind+1,hind,msum+mint[mind],hsum,ans);
       }
       solve(tar,count,mind+1,hind,msum,hsum,ans);
    }
    if(hind<4){
        if(hsum<hr[hind]<12){
            solve(tar,count+1,mind,hind+1,msum,hsum+hr[hind],ans);
        }
        solve(tar,count,mind,hind+1,msum,hsum,ans);
    }
    
    

   }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
       for(int h=0;h<12;h++){
        for(int m=0;m<60;m++){
            if(__builtin_popcount(h)+ __builtin_popcount(m)==turnedOn){
                string s= to_string(h) +":";
                if(m<10) s+="0";
                s+=to_string(m);
                ans.push_back(s); 
            }
        }
       }
       return ans;

    }
};