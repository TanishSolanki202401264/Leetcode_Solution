/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int XORR=0;
            for(int i=0;i<n;i++){
                XORR=XORR^nums[i];
            }
            int rightmost=XORR & -XORR;
            int b1=0;
            int b2=0;
            for(int i=0;i<n;i++){
                if(nums[i] & rightmost){
                    b1=b1^nums[i];
                }
                else{
                    b2=b2^nums[i];
                }
            }
            return {b1,b2};
    }
};*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XORR = 0;

        for(int x : nums) {
            XORR ^= x;
        }

        long long rightmost = XORR & -XORR;

        int b1 = 0, b2 = 0;

        for(int x : nums) {
            if(x & rightmost)
                b1 ^= x;
            else
                b2 ^= x;
        }

        if(b1 > b2) swap(b1, b2);

        return {b1, b2};
    }
};
