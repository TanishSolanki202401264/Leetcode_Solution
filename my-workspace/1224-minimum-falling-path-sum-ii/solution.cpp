class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = grid[n-1][j];
        }
        for (int i =n-2;i >= 0;i--) {
            for (int j = 0; j < n; j++) {
                int ans = 1e9;
                for (int col = 0; col < n; col++) {
                    if (col != j) {
                        ans = min(ans, dp[i + 1][col]);
                    }
                }
                dp[i][j] = grid[i][j] + ans;
            }
        }
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};
