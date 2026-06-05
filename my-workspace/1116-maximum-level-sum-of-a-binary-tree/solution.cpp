class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int ansLevel = 1;
        int maxSum = INT_MIN;

        while(!q.empty()) {
            int n = q.size();
            int sum = 0;

            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left != NULL) {
                    q.push(temp->left);
                }

                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }

            if(sum > maxSum) {
                maxSum = sum;
                ansLevel = level;
            }

            level++;
        }

        return ansLevel;
    }
};
