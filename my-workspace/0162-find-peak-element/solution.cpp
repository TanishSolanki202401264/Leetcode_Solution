class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            bool leftOK = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool rightOK = (mid == nums.size() - 1) || (nums[mid] > nums[mid + 1]);

            if(leftOK && rightOK) {
                return mid; 
            }
            else if(!rightOK) {
                start = mid + 1; 
            }
            else {
                end = mid - 1; 
            }
        }
        return -1; 
    }
};

