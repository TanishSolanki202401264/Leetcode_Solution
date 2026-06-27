class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        for(int x : nums)
            freq[x]++;
        int ans = 1;
        if(freq.count(1)) {
            int c = freq[1];
            if(c % 2 == 0)
                c--;
            ans = max(ans, c);
        }
        for(auto &it : freq) {
            long long x = it.first;
            if(x == 1)
                continue;
            int len = 0;
            while(freq[x] >= 2) {
                if(x > 1e9 / x)
                    break;
                long long nxt = x * x;
                if(freq.find(nxt) == freq.end())
                    break;
                len += 2;
                x = nxt;
            }
            if(freq[x] >= 1)
                len++;

            ans = max(ans, len);
        }

        return ans;
    }
};
