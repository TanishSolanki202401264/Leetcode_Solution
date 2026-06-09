class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long diff=(long long)nums[n-1]-nums[0];
        return diff*(long long)k;
    }
};
