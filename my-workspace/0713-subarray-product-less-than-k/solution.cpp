class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int n=nums.size();
         int start=0;
         int end=0;
         int product=1;
         int count=0;
         while(end<n){
           product=product*nums[end];
  //product ae k thii nano hovo joie jo product ae k thii moto hashe to nahi chale
        while(product>=k && start<=end){
            product=product/nums[start];
            start++;}
   count=count+(end-start+1);
         end++;
         }
         return count;
    }
};
