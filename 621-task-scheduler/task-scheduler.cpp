class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mpp(26);
        for(char ch:tasks){
            mpp[ch-'A']++;
        }
        int time=0;
        priority_queue<int>pq;
        for(int i=0;i<mpp.size();i++){
            if(mpp[i]>0){
                pq.push(mpp[i]);
            }
            
        }
        int ans=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto& f:temp){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                ans+=temp.size();
            }
            else ans+=n+1;
        }
        return ans;
    }
};