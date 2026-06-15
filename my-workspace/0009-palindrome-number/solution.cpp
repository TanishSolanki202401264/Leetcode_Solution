class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; 

        int original = x;
        int reversed = 0;

        while (x > 0) {
            int lastdigit = x % 10;
            x = x / 10;
            if (reversed > (INT_MAX - lastdigit) / 10) return false;
            reversed = reversed * 10 + lastdigit;
        }

        return reversed == original;
    }
};
