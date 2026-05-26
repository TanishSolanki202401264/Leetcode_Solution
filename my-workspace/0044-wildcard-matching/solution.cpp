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
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // both exhausted
        dp[0][0] = true;

        // pattern empty but string not empty
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // string empty but pattern may contain *
        for (int j = 1; j <= m; j++) {

            bool flag = true;

            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // character match or '?'
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {

                    dp[i][j] = dp[i - 1][j - 1];
                }

                // '*'
                else if (p[j - 1] == '*') {

                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
