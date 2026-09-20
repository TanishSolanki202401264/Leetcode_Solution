class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return (n==1 ?nums[0]:0);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                sum=sum+nums[i];
            }
            else{
                sum=sum-nums[i];
            }
        }
      long long minie=4e18;
        long long cur=0;
        for(int i=0;i+1<n;i=i+2){
            long long x=(long long)nums[i]-nums[i+1];
            cur=min(x,cur+x);
            minie=min(minie,cur);
        }
        cur=0;
        for(int i=1;i+1<n;i=i+2){
            long long x=(long long)-nums[i]+nums[i+1];
            cur=min(x,cur+x);
            minie=min(minie,cur);
        }
        if(minie==(long long)4e18){
            return sum;
        }
        return max(sum,sum-2*minie);
    }
};
