class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int mx=0;
        for(int x:nums){
            ans+=__builtin_popcount(x);
            mx=max(mx,x);
        }
        if(mx==0){
            return ans;
        }
        while(mx>1){
            ans++;
            mx>>=1;
        }
        return ans;
     }
};
