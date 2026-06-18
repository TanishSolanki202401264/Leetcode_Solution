class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Basic level of MAP no apanane saro use sikhavade cheee
     unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0; i<n;i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>n/2) {
                return nums[i];
            }
        }
        return -1;
    }
};
