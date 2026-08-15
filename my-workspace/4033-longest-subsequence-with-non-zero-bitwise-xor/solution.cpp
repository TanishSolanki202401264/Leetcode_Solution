class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       //NOTE: Koi pan no zero sathe no xor ae je te number j as answer apse and be same number no xor ae always zero j thase 
       //ahiya suppose ke xorr=xorr^it am agal vadhe chee to te case ma apde aavo ak number find kariye ke jethii hasnonzero true thay to ae case ma return karvanu rahse n-1 and else na case m,a return karvanu n ne 
       int n=nums.size();
        int xorr=0;
        bool hasNonzero=0;
        for(int it:nums){
            xorr=xorr^it;
            if(it!=0){
                hasNonzero=1;
            }
        }
        if(xorr!=0){
            return n;
        }
        if(hasNonzero){
            return n-1;
        }
        return 0;
    }
};
