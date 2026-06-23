class Solution {
public:

    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long totalFlowers = 1LL * m * k;

        if (totalFlowers > bloomDay.size())
            return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;       // possible answer
                end = mid - 1;   // search left for smaller day
            } else {
                start = mid + 1; // need more days
            }
        }

        return ans;
    }
};
