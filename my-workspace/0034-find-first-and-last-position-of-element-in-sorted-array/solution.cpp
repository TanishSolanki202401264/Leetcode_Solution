class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        int a1 = -1;
        while (start <= end) {
            int mid =start+(end-start)/2;
            if (nums[mid] ==target) {
                a1 = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        start = 0;
        end = n - 1;
        int a2 = -1;
        while (start <= end) {
            int mid = start +(end-start)/ 2;
            if (nums[mid] == target) {
                a2 = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return {a1, a2};
    }
};
