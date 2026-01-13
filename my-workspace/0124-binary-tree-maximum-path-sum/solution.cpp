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
/*class Solution {
public:
     int Pathsum(TreeNode*root,int &sum){
        if(root==NULL){
            return 0;
        }
        //leaf node
        if(!root->left && !root->right){
            return root->val;
        }

        int left=Pathsum(root->left,sum);
        int right=Pathsum(root->right,sum);

        //if left and right both exists
        if(root->left && root->right){
            sum=max(sum,root->val+left+right);
            return root->val+max(left,right);
        }
        //only left exists
        if(root->left){
            return root->val+left;
        }
        if(root->right){
            return root->val+right;
        }
     }



    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        int value=Pathsum(root,sum);
        if(root->left && root->right){
            return sum;
        }
        return max(sum,value);
    }
};*/
/*aa code only from leaf to leaf na maximum path mate no chee 
have for any node maximum path no code*/
class Solution {
public:
    int sum = INT_MIN;
    int Pathsum(TreeNode* root) {
        if(root == NULL) return 0;
        int left = max(0, Pathsum(root->left));
        int right = max(0, Pathsum(root->right));
        sum = max(sum, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        Pathsum(root);
        return sum;
    }
};

