class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        int longest = 0;

        for(int x : st) {

            // sequence ની શરૂઆત
            if(st.find(x - 1) == st.end()) {

                int curr = x;
                int count = 1;

                while(st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
