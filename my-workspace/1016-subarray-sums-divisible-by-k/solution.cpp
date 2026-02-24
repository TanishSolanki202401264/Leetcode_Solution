class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int prefixsum=0;
      unordered_map<int,int>m;
      m[0]=1;
      for(int i=0;i<n;i++){
        prefixsum=prefixsum+nums[i];
        int rem=prefixsum%k;
        if(rem<0){
            rem=rem+k;     
              }
              if(m.count(rem)){
                total=total+m[rem];
                m[rem]++;
              }
              else{
                m[rem]=1;
              }
      }   
        return total;
    }
};
