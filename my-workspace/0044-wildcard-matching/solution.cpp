/*class Solution {
public:
 int f(int i,int j,string &s,string &p){
    //base case

    if(i<0 && j<0){
        return 1;
    }
    if(i<0 && j>=0){
        return 0;
    }
    if(j<0  && i>=0){
        for(int ii=0;ii<=j;ii++){
            if(p[ii]!='*'){
                return 0;
            }
        }
        return 1;
    }
   if(s[i]==p[j] || s[i]=='?'){
    return f(i-1,j-1,s,p);
   }
  if(s[i]=='*'){
    return f(i-1,j,s,p) | f(i,j-1,s,p);
  }
    return 0;
  }
 bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return f(n-1,m-1,s,p);
    }
};*/
//ama text and pattern undhii thai gayi chee s ae text chee and p ae pattern thase

class Solution {
public:
    int f(int i, int j, string &s, string &p,vector<vector<int>>&dp) {

        if (i < 0 && j < 0) {
            return 1;
        }
        if (j < 0 && i >= 0) {
            return 0;
        }
        if (i < 0 && j >= 0) {
            for (int jj = 0; jj <= j; jj++) {
                if (p[jj] != '*') {
                    return 0;
                }
            }
            return 1;
        }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j]= f(i - 1, j - 1, s, p,dp);
        }
        if (p[j] == '*') {
            return dp[i][j]= f(i - 1, j, s, p,dp) || f(i, j - 1, s, p,dp);
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
     vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return f(n - 1, m - 1, s, p,dp);
    }
};
