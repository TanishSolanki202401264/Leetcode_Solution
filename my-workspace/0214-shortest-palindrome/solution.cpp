class Solution {
public:

    vector<int> zFunction(string s) {
        int n = s.size();
        vector<int> z(n);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i <= R)
                z[i] = min(R - i + 1, z[i - L]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > R) {
                L = i;
                R = i + z[i] - 1;
            }
        }
        return z;
    }
    string shortestPalindrome(string s) {
        if (s.empty())
            return "";
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s + "$" + rev;
        vector<int> z =zFunction(temp);
        int n =s.size();
        int longest = 0;
        for (int i=n+1;i<temp.size();i++) {
            if (i+z[i]==temp.size()) {
                longest=max(longest,z[i]);
            }
        }
        string remain = s.substr(longest);
        reverse(remain.begin(), remain.end());
        return remain + s;
    }
};
