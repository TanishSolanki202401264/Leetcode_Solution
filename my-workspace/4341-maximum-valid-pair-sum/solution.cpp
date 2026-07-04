class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int ans=INT_MIN;
        for(int i=k;i<n;i++){
            ans=max(ans,nums[i-k]);
            maxi=max(maxi,ans+nums[i]);
        }
       
        return maxi;
    }
};
