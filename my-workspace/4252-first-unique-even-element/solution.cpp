class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
       int n=nums.size();
      //sorting vali approach ahiya kam nahi kare kem ke apde first unique even joie chhiye to index pamn pahela avavo joie ne 
     unordered_map<int,int> freq;
   for(int x:nums){
    freq[x]++;
     }
      int ans=-1;
      for(int i=0;i<n;i++){
        if(freq[nums[i]]==1 && nums[i]%2==0){
            ans=nums[i];
            break;
        }
      }
      return ans;
    }
};
