class Solution {
public:
int f(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx==0) {
            if (sum==0 && arr[0]==0) return 2;
            if (sum==0||sum==arr[0]) return 1;
            return 0;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        int nottake = f(idx-1, sum, arr, dp);

        int take =0;
        if (arr[idx]<=sum) {
            take = f(idx-1,sum-arr[idx],arr,dp);
        }

        return dp[idx][sum]=take+nottake;
    }
    int findways(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(tar+1,-1));
        return f(n-1,tar,arr,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
          int totalsum = 0;
        for (auto &it :nums) {
            totalsum += it;
        }
        if ((totalsum -target< 0) || (totalsum -target) % 2 != 0) {
            return 0;
        }
        return findways(nums,(totalsum-target)/2);
    }
};
