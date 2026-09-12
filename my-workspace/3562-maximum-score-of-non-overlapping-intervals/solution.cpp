class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        vector<long long> rights(n);

        for (int i = 0; i < n; i++)
            rights[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            int pos = lower_bound(
                rights.begin(),
                rights.begin() + i,
                a[i][0]
            ) - rights.begin();

            prev[i] = pos - 1;
        }

        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

        for (int i = 1; i <= n; i++) {

            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                Node skip = dp[i - 1][k];

                Node take;

                take.score =
                    a[idx][2] +
                    dp[prev[idx] + 1][k - 1].score;

                take.ids =
                    dp[prev[idx] + 1][k - 1].ids;

                take.ids.push_back(a[idx][3]);

                sort(take.ids.begin(), take.ids.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[n][4].ids;
    }
};
