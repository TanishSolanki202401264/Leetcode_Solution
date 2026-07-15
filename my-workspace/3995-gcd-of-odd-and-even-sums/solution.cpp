class Solution {
public:
 
    int gcdOfOddEvenSums(int n) {
     int x= n*(2*n+1);
        int y= n*(n+1);
        return __gcd(y,x);
    }
};
