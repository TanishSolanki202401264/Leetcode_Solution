class Solution {
public:
    int minDays(int n) {
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int sum=1;sum<=n;sum++){
            for(int k=1;k*(k+1)/2<=sum;k++){
                int x=k*(k+1)/2;
                if(x==sum){
                    dp[sum]=min(dp[sum],k);
                }
                else{
                    dp[sum]=min(dp[sum],dp[sum-x]+k+1);
                }
            }
        }
        return dp[n];
    }
};
