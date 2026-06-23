class Solution {
public:

    int findMaxRow(vector<vector<int>>& mat, int col) {

        int row = 0;

        for(int i = 0; i < mat.size(); i++) {
            if(mat[i][col] > mat[row][col]) {
                row = i;
            }
        }

        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int start = 0;
        int end = n - 1;

        while(start <= end) {

            int mid = start + (end - start) / 2;

            int row = findMaxRow(mat, mid);

            int left =
                (mid - 1 >= 0)
                ? mat[row][mid - 1]
                : -1;

            int right =
                (mid + 1 < n)
                ? mat[row][mid + 1]
                : -1;

            if(mat[row][mid] > left &&
               mat[row][mid] > right) {

                return {row, mid};
            }

            else if(left > mat[row][mid]) {
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }

        return {-1, -1};
    }
};
