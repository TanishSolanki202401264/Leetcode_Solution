class Solution {
public:
     int f(int idx,int T,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==0){
            if(T%nums[0]==0){
                return  T/nums[0];
            }
            return 1e9;
        }
   if(dp[idx][T]!=-1){
    return dp[idx][T];
   }
        int nottake=0+f(idx-1,T,nums,dp);
        int take=INT_MAX;
        if(nums[idx]<=T){
            take=1+f(idx,T-nums[idx],nums,dp);
        }
        return  dp[idx][T] =  min(take,nottake);
     }




    int coinChange(vector<int>& coins, int amount) {
      int n=coins.size();
      vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
      int ans= f(n-1,amount,coins,dp);
      if(ans>=1e9){
        return -1;
      }
      return ans;
    }
};
