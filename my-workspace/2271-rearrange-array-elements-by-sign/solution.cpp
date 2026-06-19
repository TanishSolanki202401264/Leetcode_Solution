class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans1;
        vector<int>ans2;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans1.push_back(nums[i]);
            }
            if(nums[i]<0){
                ans2.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<ans1.size();i++){
            ans.push_back(ans1[i]);
            ans.push_back(ans2[i]);
        }
        return ans;
    }
};
