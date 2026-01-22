class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
                int n = matrix.size();

        // Min heap: {value, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // Push first element of each row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int ans = 0;

        while (k--) {
            auto element = pq.top();
            pq.pop();

            ans = element.first;
            int row = element.second.first;
            int col = element.second.second;

            // push next element in same row
            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return ans;
    }
};
