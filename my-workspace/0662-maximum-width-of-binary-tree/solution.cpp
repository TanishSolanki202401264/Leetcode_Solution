class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int n = q.size();

            long long first = q.front().second;
            long long last = q.back().second;

            ans = max(ans, last - first + 1);

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();

                idx = idx - first; // overflow avoid કરવા normalize

                if(node->left != NULL) {
                    q.push({node->left, 2 * idx + 1});
                }

                if(node->right != NULL) {
                    q.push({node->right, 2 * idx + 2});
                }
            }
        }

        return (int)ans;
    }
};
