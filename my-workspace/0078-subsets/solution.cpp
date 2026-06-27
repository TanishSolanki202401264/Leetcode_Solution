class Solution {
public:
      void solve(int idx,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        if(idx==nums.size()){
          ans.push_back(curr);
          return;
        }
//take
curr.push_back(nums[idx]);
        solve(idx+1,nums,curr,ans);
  curr.pop_back();
          solve(idx+1,nums,curr,ans);
      }
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>>ans;
            vector<int>curr;
            solve(0,nums,curr,ans);
            return ans;
    }
};
