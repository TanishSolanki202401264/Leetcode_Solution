class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){
            int index=i%n;
            while(!st.empty() && nums[st.top()]<nums[index]){
                ans[st.top()]=nums[index];
                st.pop();
            }
            if(i<n){
                st.push(index);
            }

        }
        return ans;
    }
};
