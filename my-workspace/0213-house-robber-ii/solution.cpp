class Solution {
public:
  int f(int idx,vector<int>&nums,vector<int>&dp){
      if(idx==0){
          return nums[idx];
      }
      if(idx<0){
          return 0;
      }
      if(dp[idx]!=-1){
          return dp[idx];
      }
      int pick=nums[idx]+f(idx-2,nums,dp);
      int notpick=f(idx-1,nums,dp);
      return dp[idx]=max(pick,notpick);
  }
   long long  int rob(vector<int>& nums) {
             int n=nums.size();
        if(n==1){
            return nums[0];
        }
           vector<int>a;
       vector<int>b;
     
        //first ne consider na karo
        for(int i=0;i<n-1;i++){
            a.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            b.push_back(nums[i]);
        }
       int x=a.size();
       int y=b.size();
        vector<int>dp1(x,-1);
        vector<int>dp2(y,-1);
       int ans1=f(a.size()-1,a,dp1);
       int ans2=f(b.size()-1,b,dp2);
       return max(ans1,ans2);
    }
};
