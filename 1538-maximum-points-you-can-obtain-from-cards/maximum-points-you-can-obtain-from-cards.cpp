class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        if(k==cardPoints.size()) return sum;
        int r=k-1;
        int l=cardPoints.size()-1;
        int temp=sum;
        while(r>=0){
            temp+=cardPoints[l]-cardPoints[r];
            sum=max(sum,temp);
            r--;
            l--;

        }
        return sum;

    }
};