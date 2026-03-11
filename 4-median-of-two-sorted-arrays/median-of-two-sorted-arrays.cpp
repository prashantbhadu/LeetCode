class Solution {
public:
    vector<int>func(vector<int>& nums1, vector<int>& nums2){
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++,j++;
            }
        }
        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans=func(nums1,nums2);
       double rest;
       if(ans.size()%2==0){
        int med=ans.size()/2;
        rest=(ans[med]+ans[med-1])/2.0;
        return rest;
       }
       else{
         return rest=ans[ans.size()/2];
       }
    }
};