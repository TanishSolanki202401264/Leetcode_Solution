class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            int mini = min(a, min(b, c));
            if(mini != -1)
                ans += mini + 1;
        }
        return ans;
    }
};
