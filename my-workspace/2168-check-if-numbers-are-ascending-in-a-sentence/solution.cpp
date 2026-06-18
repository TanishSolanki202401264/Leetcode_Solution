class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> ans;
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                ans.push_back(num);
            }
            else {
                i++;
            }
        }
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1])
                return false;
        }
        return true;
    }
};
