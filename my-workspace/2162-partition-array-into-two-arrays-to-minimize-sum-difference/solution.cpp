class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(),nums.begin() + n);
        vector<int> right(nums.begin() + n,nums.end());
        vector<vector<int>>leftSum(n + 1),rightSum(n + 1);
        for (int mask =0;mask<(1 << n);mask++) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }
            leftSum[cnt].push_back(sum);
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }
            rightSum[cnt].push_back(sum);
        }
        for (int i = 0; i <= n; i++)
            sort(rightSum[i].begin(), rightSum[i].end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        for (int cntLeft = 0; cntLeft <= n; cntLeft++) {
            int cntRight = n - cntLeft;
            for (int leftSubsetSum : leftSum[cntLeft]) {
                int target = total / 2 - leftSubsetSum;
                auto &vec = rightSum[cntRight];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) {
                    int s1 = leftSubsetSum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }
                if (it != vec.begin()) {
                    --it;
                    int s1 = leftSubsetSum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }
            }
        }
        return ans;
    }
};
