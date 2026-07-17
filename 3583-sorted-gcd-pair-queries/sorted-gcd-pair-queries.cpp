class Solution {
public:
    
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
       int maxval=*max_element(nums.begin(),nums.end());
       vector<long long> freq(maxval+1,0);
       for(int x:nums)
            freq[x]++;
        vector<long long>divcnt(maxval+1,0);
            for(int g=1;g<=maxval;g++){
                for(int x=g;x<=maxval;x+=g){
                    divcnt[g]+=freq[x];
                }
            }
            vector<long long>exact(maxval+1,0);
            for(int g=maxval; g>=1;g--){
                exact[g]=divcnt[g]*(divcnt[g]-1)/2;
                for(int m=2*g;m<=maxval;m+=g){
                    exact[g]-=exact[m];
                }
            }
            vector<long long>prefix(maxval+1,0);
            for(int g=1;g<=maxval;g++){
                prefix[g]=prefix[g-1] + exact[g];
            }  
            vector<int>ans;
            for(long long q:queries){
                int g=lower_bound(prefix.begin()+1,prefix.end(),q+1)-prefix.begin();
                ans.push_back(g);
            }
            return ans;
    }
};