class Solution {
public:
    void sortColors(vector<int>& nums) {
      //NOW IT IS THE REAL SOLUTION OF THIS PROBLEM
      int count0=0;
      int count1=0;
      int count2=0;
      int n= nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==0){
            count0++;
        }
        if(nums[i]==1){
            count1++;
        }
        if(nums[i]==2){
            count2++;
        }
      }
      vector<int>ans;
      for(int i=0;i<count0;i++){
        ans.push_back(0);
      }
       for(int i=0;i<count1;i++){
        ans.push_back(1);
      }
       for(int i=0;i<count2;i++){
        ans.push_back(2);
      }
      nums=ans;
    }
};
