class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         //THIS IS ONLY FOR FUN PURPOSE SO DO NOT JUDGE
         sort(nums.begin(),nums.end());
         reverse(nums.begin(),nums.end());
         return nums[k-1];
    }
};
