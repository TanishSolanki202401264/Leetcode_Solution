class Solution {
public:
   int f(int idx,vector<int>&nums,int k,vector<int>&dp){
    int n=nums.size();
    if(idx==n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int len=0;
    int maxi=INT_MIN;
    int maxAns=INT_MIN;
    for(int j=idx;j<min(idx+k,n);j++){
        len++;
        maxi=max(maxi,nums[j]);
        int sum=len*maxi +f(j+1,nums,k,dp);
        maxAns=max(maxAns,sum);
    }
    return dp[idx]= maxAns;
   }



    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return f(0,arr,k,dp);
    }
};
