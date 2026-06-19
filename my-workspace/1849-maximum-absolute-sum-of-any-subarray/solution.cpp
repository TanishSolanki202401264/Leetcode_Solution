class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
          int n=nums.size();
        int maxi=INT_MIN;
        int prefix=0;
        for(int i=0;i<n;i++){
           prefix=prefix+nums[i];
           maxi=max(maxi,prefix);
           if(prefix<0){
            prefix=0;
           }
        }
        //ahiya maximum and minsum banne find karva padse
        int sum1=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            sum1=sum1+nums[i];
            mini=min(mini,sum1);
            if(sum1>0){
                sum1=0;
            }
        }
        return max(maxi,abs(mini));
    }
};
