//tabulation
//tc = on, sc = on better than memoization
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int n1 = 1, n2 = 0, cn;
        for(int i = 2; i <= n; i++){
            cn = n1+n2;
            n2 = n1, n1 = cn;
        }
        return cn;
    }
};
