class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid =start +(end-start)/2;

            // mid ne even banavo
            if (mid%2==1)
                mid--;

            if (nums[mid]==nums[mid+1]) {
                // unique right side ma che
                start=mid+2;
            }
            else {
                // unique left side ma che
                end=mid;
            }
        }

        return nums[start];
    }
};
