class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long int total=0;
        long long int prefixsum=0;
      unordered_map<long long int,long long int>m;
      m[0]=1;
      for(int i=0;i<n;i++){
        prefixsum=prefixsum+nums[i];
        if(m.count(prefixsum-k)){
            total=total+m[prefixsum-k];
            m[prefixsum]++;
        }
        else{
            m[prefixsum]++;
        }
      }
  return total;
    }
};
