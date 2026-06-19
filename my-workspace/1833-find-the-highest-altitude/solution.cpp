class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>ans(n+1,0);
        ans[0]=0;
        ans[1]=gain[0];
        for(int i=0;i<n-1;i++){
            ans[i+2]=ans[i+1]+gain[i+1];
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};
