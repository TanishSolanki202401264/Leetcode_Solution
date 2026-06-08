class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n=nums.size();
        if(n<2){
            return 0;
        }
       
        sort(nums.begin(),nums.end());
        long long maxi=LLONG_MIN;
        for(long long i=1;i<=n-1;i++){
           maxi=max(maxi,(long long)nums[i]-nums[i-1]);
        }
        return maxi;
    }
};
