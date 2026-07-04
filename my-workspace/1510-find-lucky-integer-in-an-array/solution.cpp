class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int ans=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==arr[i]){
                ans=arr[i];
                 maxi=max(maxi,ans);
            }
       
        }
        return maxi;
    }
};
