class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<int> cnt;
        for(int i = 1; i < strs.size(); i++) {
            int j = 0;
            while(j < strs[0].size() &&
                  j < strs[i].size() &&
                  strs[0][j] == strs[i][j]) {

                j++;
            }
            cnt.push_back(j);
        }

        int mini = INT_MAX;
        for(int x : cnt) {
            mini = min(mini, x);
        }
        return strs[0].substr(0, mini);
    }
};
