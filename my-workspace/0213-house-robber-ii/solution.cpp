class Solution {
public:
  long long int rob2(vector<long long int>& nums1) {
        long long int n=nums1.size();
        //aa curr,prev and prev2 valu logic will be the best because space optimize karine apee chee bahu vadhare padtii
   if (n == 0) return 0;
        if (n == 1) return nums1[0];
      
       long long  int prev=nums1[0];
        long long int prev2=0;
        for(int i=1;i<n;i++){
           long long  int take=nums1[i];
            if(i>1){
                take=take+prev2;
        }
        long long int nottake=0+prev;

        long long int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;}








   long long  int rob(vector<int>& nums) {
     long long int n=nums.size();
    if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<long long int>temp1,temp2;
       
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(rob2(temp1),rob2(temp2));
    }
};
