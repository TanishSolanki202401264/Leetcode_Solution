class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        long long total=0;
        int count=0;
        int start=0;
        int end=0;
        while(end<n){
          //window length ne increase karvii chhavi
            //jya sudhii maxelement ae K ne equal na thai jay
            if(nums[end]==maxi){
                count++;
            }
          while(count==k){
            total=total+(n-end);
            if(nums[start]==maxi){
                count--;
            }
            start++;
          }

            end++;
        }
        return total;
    }
};
