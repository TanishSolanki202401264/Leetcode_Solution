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
  bool solve(TreeNode*root,int sum,int targetSum){
    if(root==NULL){
        return 0;
    }
//ahiya ae pan check karvanu ke te leaf node chee ke nahi ae khub j important task chee
    sum=sum+root->val;
    if(root->left==NULL && root->right==NULL && sum==targetSum){
        return 1;
    }
   return solve(root->left,sum,targetSum) ||
    solve(root->right,sum,targetSum);
  }
    bool hasPathSum(TreeNode* root, int targetSum) {
        //GFG na path from root to specified sum mate no code
      return  solve(root,0,targetSum);

    }
};
