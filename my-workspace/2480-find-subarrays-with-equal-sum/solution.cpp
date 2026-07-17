class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int sum=0;
        for(int i=0;i<n-1;i++){
           sum=nums[i]+nums[i+1];
           ans.push_back(sum);
        }
    sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++){
             if(ans[i]==ans[i+1]){
                return 1;
             }
        }
        return 0;
    }
};
