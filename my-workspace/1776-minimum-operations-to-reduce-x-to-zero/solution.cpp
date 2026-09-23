class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        long long target=sum-x;
        if(target<0){
            return -1;
        }
        if(target==0){
            return n;
        }
        int left=0;
        long long sum1=0;
        int len=-1;
        for(int right=0;right<n;right++){
            sum1=sum1+nums[right];


            while(left<=right && sum1>target){
                sum1=sum1-nums[left];
                left++;
            }

            if(sum1==target){
                len=max(len,right-left+1);
            }
        }
        if(len==-1){
            return -1;
        }
        return n-len;
    }
};
