class Solution {
public:
  
  bool f(int idx,int sum1,vector<int>&arr,vector<vector<int>>&dp){
      if(sum1==0){
          return true;
      }
      if(idx==0){
          return (arr[0]==sum1);
      }
      if(dp[idx][sum1]!=-1){
          return dp[idx][sum1];
      }
      bool notTake=f(idx-1,sum1,arr,dp);
      bool Take=false;
      if(arr[idx]<=sum1){
          Take=f(idx-1,sum1-arr[idx],arr,dp);
      }
      return dp[idx][sum1]=Take | notTake ;
  }
  




    bool canPartition(vector<int>& nums) {
         int n=nums.size();
           int totalsum=0;
           for(int i=0;i<n;i++){
            totalsum=totalsum+nums[i];
           }
           if(totalsum%2!=0){
            return 0;
           }
         int sum1=totalsum/2;


        vector<vector<int>>dp(n+1,vector<int>(sum1+1,-1));
         return f(n-1,sum1,nums,dp);
    }
};
