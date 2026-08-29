class Solution {
public:
    string makePalindrome(string &half, char mid) {
        string ans = half;
        if (mid != '#') ans += mid;
        string rev = half;
        reverse(rev.begin(), rev.end());
        ans += rev;
        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;

        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1) return "";

        vector<int> halfFreq(26);
        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        vector<int> used(26);
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';
            used[x]++;
            if (used[x] > halfFreq[x]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            bool exact = true;

            for (int i = 0; i < 26; i++) {
                if (used[i] != halfFreq[i]) {
                    exact = false;
                    break;
                }
            }

            if (exact) {
                string half = target.substr(0, m);
                string candidate = makePalindrome(half, mid);

                if (candidate > target)
                    return candidate;
            }
        }

        for (int pos = m - 1; pos >= 0; pos--) {
            vector<int> prefix(26);
            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';
                prefix[x]++;

                if (prefix[x] > halfFreq[x]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                if (prefix[c] >= halfFreq[c]) continue;

                vector<int> remaining = halfFreq;

                for (int i = 0; i < 26; i++)
                    remaining[i] -= prefix[i];

                remaining[c]--;

                string half = target.substr(0, pos);
                half += char('a' + c);

                for (int i = 0; i < 26; i++)
                    half += string(remaining[i], char('a' + i));

                return makePalindrome(half, mid);
            }
        }

        return "";
    }
};
