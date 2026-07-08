class Solution {
public:
    int mdo=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<long long>pow10(n+1,1);
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mdo;
        }
        vector<int>ind(n+1,0);
        vector<long long>val(n+1,0);
        vector<long long>total(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                cnt++;
                val[cnt]=(val[cnt-1]*10+digit)%mdo;
                total[cnt]=total[cnt-1] + digit;
            }
            ind[i+1]=cnt;
        }
        vector<int>ans;
        for(auto&q : queries){
            int l=q[0];
            int r=q[1];
            int left=ind[l];
            int right=ind[r+1];
            if(left==right){
                ans.push_back(0);
                continue;
            }
            int len = right-left;
            long long number =(val[right]-val[left]*pow10[len])%mdo;
            if(number<0)number+=mdo;
            long long sum =total[right]-total[left];
            ans.push_back((number*sum)%mdo);
        }
        return ans;
    }
};