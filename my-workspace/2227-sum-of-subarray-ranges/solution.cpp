class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n=nums.size();
         long long sum=0;
        for(long long i=0;i<n;i++){
            long long mini=LLONG_MAX;
            long long maxi=LLONG_MIN;
            for(long long  j=i;j<n;j++){
                maxi=max(maxi,(long long)nums[j]);
                mini=min(mini,(long long)nums[j]);
                sum=sum+(maxi-mini);
            }

        }
        return sum;
    }
};
