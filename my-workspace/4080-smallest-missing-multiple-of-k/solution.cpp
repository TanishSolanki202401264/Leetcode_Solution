class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      for(int i=1; ;i++){
        int multiple=k*i;

        if(find(nums.begin(),nums.end(),multiple)==nums.end()){
            return multiple;
        }
      }
    }
};
