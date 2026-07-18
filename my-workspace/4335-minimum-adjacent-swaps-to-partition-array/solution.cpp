class Solution {
public:
    const long long MOD=1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            if(nums[i]<a){
                arr[i]=0;
            }
            else if(nums[i]<=b){
                arr[i]=1;
            }
            else{
                arr[i]=2;
            }
        }
        long long answer[3]={0,0,0};
        long long count=0;
        for(int i=0;i<n;i++){
            int x=arr[i];
            for(int j=x+1;j<3;j++){
                count=(count+answer[j])%MOD;
            }
            answer[x]++;
        }
        return (int)count;
    }
};
