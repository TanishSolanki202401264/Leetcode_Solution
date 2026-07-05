class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int ans=0;
        int maxi=INT_MIN;
        for(int i=1;i<=n-1;i++){
            ans=points[i][0]-points[i-1][0];
            maxi=max(ans,maxi);
        }
       return maxi;
    }
};
