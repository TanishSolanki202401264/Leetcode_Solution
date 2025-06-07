class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row_index;
        int column_index;
        int start=0;
        int end=m*n-1;
        while(start<=end){
           int mid=start+(end-start)/2;
           row_index=mid/n;
           column_index=mid%n;
           if(matrix[row_index][column_index]==target){
            return 1;
           }
           else if(matrix[row_index][column_index]<target){
            start=mid+1;
           }
           else{
            end=mid-1;
           }
        }
        return 0;
    }
};
