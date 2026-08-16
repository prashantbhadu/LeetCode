class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ind=0;
        int temp=1e9;
        int n=cost.size();
        int totalgas=0,totalcost=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalcost>totalgas) return -1;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                ind=i+1;
                curr=0;
            }
        }
        return ind;
    }
};