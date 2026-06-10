/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int solve(TreeNode* root, bool &ans) {
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            //jo Leaf node hoy tyare
            return root->val;
        }
        int leftSum = solve(root->left, ans);
        int rightSum = solve(root->right, ans);
        if(root->val!=leftSum+rightSum) {
            ans = false;
        }
        return root->val +leftSum+rightSum;
    }
    bool checkTree(TreeNode* root) {
        bool ans=1;
        solve(root,ans);
        return ans;
    }
};
