class Solution {
public:
    long long solve(string &s, int i, long long num) {
        if (i >= s.length() || !isdigit(s[i]))
            return num;
        num = num * 10 + (s[i] - '0');
        if (num > INT_MAX)
            return num;
        return solve(s, i + 1, num);
    }
    int myAtoi(string s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }
        long long num = solve(s, i, 0);
        num *= sign;
        if (num > INT_MAX)
            return INT_MAX;

        if (num < INT_MIN)
            return INT_MIN;

        return (int)num;
    }
};
