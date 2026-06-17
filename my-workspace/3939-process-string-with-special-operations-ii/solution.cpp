class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);

        long long cur = 0;

        for(int i = 0; i < n; i++) {
            char c = s[i];

            if(c >= 'a' && c <= 'z') {
                cur++;
            }
            else if(c == '*') {
                if(cur > 0) cur--;
            }
            else if(c == '#') {
                cur = min((long long)1e15, cur * 2);
            }
            else {
            }

            len[i] = cur;
        }

        if(k >= cur) return '.';

        for(int i = n - 1; i >= 0; i--) {

            long long before =
                (i == 0 ? 0 : len[i - 1]);

            char c = s[i];

            if(c >= 'a' && c <= 'z') {

                if(k == len[i] - 1)
                    return c;
            }
            else if(c == '*') {

            }
            else if(c == '#') {

                if(before > 0)
                    k %= before;
            }
            else if(c == '%') {

                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};
