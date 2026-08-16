class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=-1e9;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<=j && i<n && j>=0){
            int val=min(height[i],height[j]);
            maxi=max(maxi,val*(j-i));
            if(height[i]>height[j]) j--;
            else i++;
        }
        return maxi;
    }
};