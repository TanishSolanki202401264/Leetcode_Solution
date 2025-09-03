class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int first=-1;
        int last=-1;
        sort(nums.begin(),nums.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        start=0;
        end=nums.size()-1;

         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
      vector<int>ans;
        if (first!=-1 &&last !=-1) {
            for (int i =first; i<= last;i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
