class Solution {
public:
    int consecutiveNumbersSum(int n) {
         int ans=0;
       for(long long k=2;k*(k+1)/2<=n ;k++){
           long long temp=2LL*n;
           
           if(temp%k!=0){
               continue;
           }
           
           long long count=temp/k-k+1;
           if(count>0 && count%2==0){
               ans++;
           }
       }
       return ans+1;
    }
};
