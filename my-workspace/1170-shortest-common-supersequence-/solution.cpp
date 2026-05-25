/*class Solution {
public:
   int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
  if(s[i]==t[j]){
    return dp[i][j]= 1+f(i-1,j-1,s,t,dp);
  }
  return dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));

   }
    string shortestCommonSupersequence(string str1, string str2) {
      int n=str1.size();
        int m=str2.size();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   f(n-1,m-1,str1,str2,dp);
     string ans="";
     int i=n-1,j=m-1;
     while(i>=0 && j>=0){
        if(str1[i]==str2[j]){
            ans=ans+str1[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans=ans+str1[i];
            i--;
        }
        else{
            ans=ans+str2[j];
            j--;
        }
     }

  while(i>0){
    ans=ans+str1[i];
    i--;
  }
   while(j>0){
    ans=ans+str2[j];
    j--;
   }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";

        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
