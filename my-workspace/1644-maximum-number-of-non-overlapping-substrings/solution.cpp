class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = i;
        }

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            if(first[s[i] - 'a'] != i)
                continue;

            int l = i;
            int r = last[s[i] - 'a'];
            bool ok = true;

            for(int j = l; j <= r; j++) {
                int x = s[j] - 'a';

                if(first[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if(ok)
                v.push_back({l, r});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for(auto p : v) {
            if(p.first > end) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                end = p.second;
            }
        }

        return ans;
    }
};
