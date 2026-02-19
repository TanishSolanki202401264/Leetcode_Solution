class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        // Step 1: dp matrix banavo (default n)
        vector<vector<int>> dp(n, vector<int>(n, n));

        // Step 2: mines ne 0 mark karo
        for (int i = 0; i < mines.size(); i++) {
            int r = mines[i][0];
            int c = mines[i][1];
            dp[r][c] = 0;
        }

        // Step 3: row wise left → right and right → left
        for (int i = 0; i < n; i++) {

            int count = 0;

            // left → right
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0) {
                    count = 0;
                } else {
                    count = count + 1;
                }

                if (dp[i][j] > count) {
                    dp[i][j] = count;
                }
            }

            count = 0;

            // right → left
            for (int j = n - 1; j >= 0; j--) {

                if (dp[i][j] == 0) {
                    count = 0;
                } else {
                    count = count + 1;
                }

                if (dp[i][j] > count) {
                    dp[i][j] = count;
                }
            }
        }

        // Step 4: column wise top → bottom and bottom → top
        for (int j = 0; j < n; j++) {

            int count = 0;

            // top → bottom
            for (int i = 0; i < n; i++) {

                if (dp[i][j] == 0) {
                    count = 0;
                } else {
                    count = count + 1;
                }

                if (dp[i][j] > count) {
                    dp[i][j] = count;
                }
            }

            count = 0;

            // bottom → top
            for (int i = n - 1; i >= 0; i--) {

                if (dp[i][j] == 0) {
                    count = 0;
                } else {
                    count = count + 1;
                }

                if (dp[i][j] > count) {
                    dp[i][j] = count;
                }
            }
        }

        // Step 5: maximum value find karo
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }

        return ans;
    }
};

