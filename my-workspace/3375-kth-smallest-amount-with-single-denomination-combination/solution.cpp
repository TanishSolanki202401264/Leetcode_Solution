class Solution {
public:
   long long countWays(long long x,vector<int>coins){
    int n=coins.size();
    long long ans=0;
    for(int mask=1;mask<(1<<n);mask++){
        long long lcm=1;
        int bits=0;
        bool large=0;
        for(int i=0;i<n;i++){
            if(mask &(1<<i)){
                bits++;
                long long g=gcd(lcm,(long long)coins[i]);
                lcm=(lcm/g)*coins[i];

                if(lcm>x){
                    large=1;
                    break;
                }
            }
        }
        if(large){
            continue;
        }
        long long cnt=x/lcm;
        if(bits%2==1){
            ans=ans+cnt;
        }
        else{
            ans=ans-cnt;
        }
    }
    return ans;
   }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low=1;
        long long high=1LL*(*min(coins.begin(),coins.end()))*k;
        while(low<high){
            long long mid=low+(high-low)/2;
            if(countWays(mid,coins)>=k){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
           }
};
