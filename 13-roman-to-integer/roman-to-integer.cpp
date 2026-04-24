class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='I'){
                if(i+1<n && s[i+1]=='V'){
                    ans+=4;
                    i+=2;
                    continue;
                }
                if(i+1 < n && s[i+1]=='X'){
                    ans+=9;
                    i+=2;
                    continue;
                }
                else ans+=1;
            }
            else if(s[i]=='X'){
                if(i+1<n && s[i+1]=='L'){
                    ans+=40;
                    i+=2;
                    continue;
                }
                if(i+1 < n && s[i+1]=='C'){
                    ans+=90;
                    i+=2;
                    continue;
                }
                else ans+=10;
            }
            else if(s[i]=='C'){
                if(i+1<n && s[i+1]=='D'){
                    ans+=400;
                    i+=2;
                    continue;
                }
                if(i+1 < n && s[i+1]=='M'){
                    ans+=900;
                    i+=2;
                    continue;
                }
                else ans+=100;
            }
            else if(s[i]=='V') ans+=5;
            else if(s[i]=='D')ans+=500;
            else if(s[i]=='L') ans+=50;
            else ans+=1000;
            i++;
            cout<<ans<<" ";
        }
        return ans;
    }
};