class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k), ndp(k);
        for(int x : nums) {
            fill(ndp.begin(), ndp.end(), 0);
            x %= k;
            ndp[x]++;
            for(int r = 0; r < k; r++) {
                ndp[(r * x) % k] += dp[r];
            }
            dp = ndp;
            for(int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }
        return ans;
    }
};
