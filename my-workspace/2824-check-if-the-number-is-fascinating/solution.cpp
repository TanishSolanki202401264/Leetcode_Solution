class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + 
                   to_string(2*n) + 
                   to_string(3*n);
        vector<int> freq(10,0);
        for(char c:s) {
            if(c=='0')
                return 0;
            freq[c-'0']++;
        }
        for(int i =1;i<=9;i++) {
            if(freq[i] != 1)
                return 0;
        }
        return 1;
    }
};

