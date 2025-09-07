class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ans=-1;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
            }
            else if(nums[mid]>=nums[start]){
                if(nums[start]<=target && nums[mid]>=target){
                    //left side sorted so go at right side 
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                //right side sorted so left side go
                if(nums[mid]<=target && nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};
