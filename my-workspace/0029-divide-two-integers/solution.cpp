/*class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        bool sign =true;
        if(dividend >=0 && divisor<0){
            sign =false;
        }
        else if(dividend<=0 && divisor>0){
            sign =false;
        }
        long n=abs(dividend);
        long d=abs(divisor);

        long q=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            q=q+(1<<cnt);
            n=n-(d<<cnt);

        }

        if(q==(1<<31) && sign){
            return INT_MAX;
        }
        if(q==(1<<31) && !sign){
            return INT_MIN;
        }
        return sign?q:-q;
    }
};*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = true;

        if((dividend < 0 && divisor > 0) || 
           (dividend > 0 && divisor < 0)) {
            sign = false;
        }

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long q = 0;

        while(n >= d) {
            int cnt = 0;

            while(n >= (d << (cnt + 1))) {
                cnt++;
            }

            q += (1LL << cnt);
            n -= (d << cnt);
        }

        if(sign) {
            if(q > INT_MAX) return INT_MAX;
            return (int)q;
        } else {
            if(-q < INT_MIN) return INT_MIN;
            return (int)(-q);
        }
    }
};
