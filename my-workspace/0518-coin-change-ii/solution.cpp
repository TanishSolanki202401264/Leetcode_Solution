class Solution {
public:
  int f(int idx,int T,vector<int>&coins,vector<vector<int>>&dp ){
     if(idx==0){
        return (T%coins[0]==0);
     }
     if(dp[idx][T]!=-1){
        return dp[idx][T];
     }
  int nottake= f(idx-1,T,coins,dp);
  int take=0;
  if(coins[idx]<=T){
    take=f(idx,T-coins[idx],coins,dp);
  }
   return dp[idx][T]= take+nottake;
  }

    int change(int amount, vector<int>& coins) {
       
        int n=coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       return  f(n-1,amount,coins,dp);
    }
};
