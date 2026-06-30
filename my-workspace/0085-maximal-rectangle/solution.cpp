class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() &&
                 (i==n || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i-st.top()-1;
                ans = max(ans,height*width);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>heights(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    heights[j]=0;
                }
                else{
                    heights[j]+=1;
                }
            }
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};

