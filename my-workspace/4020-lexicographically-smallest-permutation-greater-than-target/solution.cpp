class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                int x = target[i - 1] - 'a';
                if (cnt[x] == 0) {
                    break;
                }
                cnt[x]--;
            }
            int cur = target[i] - 'a';
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string candidate = target.substr(0, i);
                    candidate += char('a' + c);
                    cnt[c]--;
                    for (int x = 0; x < 26; x++) {
                        candidate += string(cnt[x], char('a' + x));
                    }
                    cnt[c]++;
                    if (ans == "" || candidate < ans) {
                        ans = candidate;
                    }
                }
            }
        }

        return ans;
    }
};
