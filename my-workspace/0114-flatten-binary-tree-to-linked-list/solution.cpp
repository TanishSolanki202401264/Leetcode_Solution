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
    void flatten(TreeNode* root) {
        while(root){
            //if left part does not exists to right ma chalya jaav prem thii puchya vagar
            if(!root->left){
                root=root->right;
            }
            else{
                TreeNode*curr=root->left;
                while(curr->right !=NULL){
                    curr=curr->right;
                }
                curr->right=root->right;
                root->right=root->left;
                root->left=NULL;
                curr=curr->right;
            }
        }
    }
};
