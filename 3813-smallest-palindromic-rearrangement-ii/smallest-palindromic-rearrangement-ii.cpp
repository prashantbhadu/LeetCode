class Solution {
public:
    long long cnr(int n,int r,int k){
        r=min(r,n-r);
        long long ways=1;
        for(int i=1;i<=r;i++){
            ways=ways*(n-r+i)/i;
            if(ways>=k) break;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
         char mid;
         if(n%2!=0){
            mid=s[n/2];
         }
         if(n==1 && k==1) return s;
         vector<int>store(26,0);
         for(int i=0;i<n/2;i++){
            store[s[i]-'a']++;
        }
        string firsthalf="";
       
        for(int i=0;i<n/2;i++){
             bool check=false;
            for(int j=0;j<26;j++){
                if(store[j]>0){
                    store[j]--;
                    long long ways=1;
                    int letters=0;
                    for(int t=0;t<26;t++){
                        letters+=store[t];
                    }
                    for(int c=0;c<26;c++){
                        if(store[c]>0){
                            ways*=cnr(letters,store[c],k);
                            letters-=store[c];
                        }
                        if(ways>=k){
                            break;
                        }
                    }
                    if(ways>=k){
                        firsthalf.push_back(j+'a');
                        check=true;
                        break;

                    }
                    k-=ways;
                    store[j]++;
                }
            }
            if(check==false) return "";
        }
      
        string rev=firsthalf;
        reverse(rev.begin(),rev.end());
        if(n%2!=0) return firsthalf+mid+rev;
        else return firsthalf+rev;

    }
};