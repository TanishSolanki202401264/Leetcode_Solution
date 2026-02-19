class Solution {
public:

    // histogram માં largest square area
    int largestSquareArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n), left(n);
        stack<int> st;

        // Next Smaller Right (NSR)
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }

        // Next Smaller Left (NSL)
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }

        // square area calculation
        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int side = min(heights[i], width);
            ans = max(ans, side * side);
        }

        return ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0);
        int ans = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j] += 1;
            }
            ans = max(ans, largestSquareArea(heights));
        }

        return ans;
    }
};

