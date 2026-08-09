class Solution {
public:
     bool f(vector<vector<int>>&mat,vector<vector<int>>&pref,int k){
           int m=mat.size();
        int n=mat[0].size();

        vector<pair<int,int>>a;

        int mr=INT_MAX;
        int mc=INT_MAX;
        int mxr=INT_MIN;
        int mxc=INT_MIN;

        for(int i=0;i+k<=m;i++){
            for(int j=0;j+k<=n;j++){
                int s=pref[i+k][j+k]-pref[i][j+k]-pref[i+k][j]+pref[i][j];

                if(s==k*k){
                    a.push_back({i,j});

                    mr=min(mr,i);
                    mxr=max(mxr,i);
                    mc=min(mc,j);
                    mxc=max(mxc,j);
                }
            }
        }

         if(a.size()<2){
             return 0;
         }

         for(auto [r,c]:a){
             if(mxr>=r+k){
                 return 1;
             }
             if(mr<=r-k){
                 return 1;
             }

             if(mxc>=c+k){
                 return 1;
             }
             if(mc<=c-k){
                 return 1;
             }
         }

         return 0;
     } 
    int maxArea(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>pref(m+1,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pref[i+1][j+1]=mat[i][j]+pref[i][j+1]+pref[i+1][j]-pref[i][j];
            }
        }
      int l=1;
        int h=min(n,m);
        int b=0;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(f(mat,pref,mid)){
                b=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return b*b;
    }
};
