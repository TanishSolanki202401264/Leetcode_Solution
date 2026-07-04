class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if( i!=(n/2) && nums[n/2]==nums[i]){
                return 0;
                break;
            }
        }
        return 1;
    }
};
