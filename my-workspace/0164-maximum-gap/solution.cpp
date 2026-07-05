class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if(n < 2)
            return 0;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        if(mini == maxi)
            return 0;
        int gap = ceil((double)(maxi - mini) / (n - 1));
        int bucketCount = (maxi - mini) / gap + 1;
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);
        for(int x : nums) {
            int idx = (x - mini) / gap;
            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
            used[idx] = true;
        }
        int ans = 0;
        int prevMax = mini;
        for(int i = 0; i < bucketCount; i++) {
            if(!used[i])
                continue;
            ans = max(ans, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return ans;
    }
};
