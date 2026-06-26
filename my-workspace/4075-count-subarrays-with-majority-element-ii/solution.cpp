class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                pref[i + 1] = pref[i] + 1;
            else
                pref[i + 1] = pref[i] - 1;
        }

        vector<int> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        int m = comp.size();

        vector<int> bit(m + 1, 0);

        auto update = [&](int idx) {
            while(idx <= m) {
                bit[idx]++;
                idx += idx & (-idx);
            }
        };

        auto query = [&](int idx) {
            int ans = 0;
            while(idx > 0) {
                ans += bit[idx];
                idx -= idx & (-idx);
            }
            return ans;
        };

        long long ans = 0;

        for(int x : pref) {

            int pos =
                lower_bound(comp.begin(), comp.end(), x)
                - comp.begin() + 1;

            ans += query(pos - 1);

            update(pos);
        }

        return ans;
    }
};
