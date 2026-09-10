class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long p = 1000;
        long long k = 1;

        while (p <= n) {
            long long q = p * 1000 - 1;
            long long r = min(n, q);

            ans += (r - p + 1) * k;

            p *= 1000;
            k++;
        }

        return ans;
    }
};

