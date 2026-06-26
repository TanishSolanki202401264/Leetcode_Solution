class Solution {
public:
    long long MOD = 1e9 + 7;
    long long power(long long x, long long n) {
        if (n == 0)
            return 1;
        long long half = power(x, n / 2);
        long long ans = (half * half) % MOD;
        if (n % 2!=0)
            ans = (ans * x) % MOD;
        return ans;
    }
    //even idx ae 4 ways addd kare jyare oddd index 5 ways add kare
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);
        return (evenWays * oddWays) % MOD;
    }
};
