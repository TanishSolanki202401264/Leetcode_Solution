class Solution {
public:
    const long long MOD=1e9+7;
    int minimumCost(vector<int>& nums, int k) {

        long long x=k;
        long long count=0;
        long long count1=0;

    for(int a:nums){
        if(x<a){
        long long count2=a-x;
        long long count3=(count2+k-1)/k;

            long long m=count+1;
            long long n=count+count3;

            __int128 c;

            if(count3%2==0){
                c=(__int128)(count3/2)*(m+n);
            }
            else{
                c=(__int128)count3*((m+n)/2);
            }
            count1=(count1+(long long)(c%MOD))%MOD;

        count=count+count3;
        x=x+count3*1LL*k;
        }

        x=x-a;
    }
    return count1;
    }
};
