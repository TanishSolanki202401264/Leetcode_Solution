class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
        //Note:fiest find next smallest on right then find next smallest of left and width will be NSR-NSL-1 and area will be height *width atle pachii temathii maximum area find kari shakvi
          int n=heights.size();
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;
        //NSR
      
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        } //koi mate NSR jo na male to
        while(!st.empty()){
           right[st.top()]=n;
           st.pop();
        }     
        //NSL

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
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

