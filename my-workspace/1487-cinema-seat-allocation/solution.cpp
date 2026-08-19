class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];
            mp[row] |= (1 << seat);
        }
        long long ans = 2LL * n;
        int leftMask =
            (1 << 2) |
            (1 << 3) |
            (1 << 4) |
            (1 << 5);
        int middleMask =
            (1 << 4) |
            (1 << 5) |
            (1 << 6) |
            (1 << 7);
        int rightMask =
            (1 << 6) |
            (1 << 7) |
            (1 << 8) |
            (1 << 9);
        for (auto &[row, mask] : mp) {
            bool left =
                (mask & leftMask) == 0;
            bool middle =
                (mask & middleMask) == 0;
            bool right =
                (mask & rightMask) == 0;
            int groups = 0;
            if (left && right) {
                groups = 2;
            }
            else if (left || middle || right) {
                groups = 1;
            }
            ans -= (2 - groups);
        }
        return ans;
    }
};
