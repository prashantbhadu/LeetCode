class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int cnt=0;
        if(arr.size()==1) return false;
        int n=arr.size();
        if(arr[0]>=arr[1] || arr[n-1]>=arr[n-2]) return false;
        int ch=0;
        bool check=false;
        for(int i=2;i<arr.size()-1;i++){
            if(arr[i]==arr[i-1]) return false;
            if(arr[i]<arr[i-1]){
                cnt++;
                ch=i;
                check=true;
                break;
            }
        }
        if(check && ch+1<=arr.size()-1){
            for(int i=ch+1;i<arr.size()-1;i++){
            if(arr[i]==arr[i-1]) return false;
            if(arr[i]>arr[i-1]){
                cnt++;
                if(cnt>1)return false;
            }
        }

        }
        
        return true;
    }
};