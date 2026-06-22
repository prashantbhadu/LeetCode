class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        for(char ch: text){
            if(ch=='b') mpp[ch]++;
            if(ch=='a')mpp[ch]++;
            if(ch=='l')mpp[ch]++;
            if(ch=='o')mpp[ch]++;
            if(ch=='n')mpp[ch]++;
        }
        int b=mpp['b'];
        int a=mpp['a'];
        int l=mpp['l']/2;
        int o=mpp['o']/2;
        int n=mpp['n'];
        return min({b,a,l,o,n});
        
    }
};