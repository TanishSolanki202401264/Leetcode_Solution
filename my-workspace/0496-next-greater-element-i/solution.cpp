class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int,int> nge; // value -> next greater

        // Step 1: nums2 માટે next greater find
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        // Step 2: nums1 માટે answer
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(nge[nums1[i]]);
        }

        return ans;
    }
};

