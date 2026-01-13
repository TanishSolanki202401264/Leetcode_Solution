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
     int ans=0;
     int chalse(TreeNode*root,int start){
        if(root==NULL){
            return 0;
        }
        if(root->val==start){
            ans=max(ans,max(chalse(root->left,start),chalse(root->right,start)));
            return -1;
            //pahela j answer ma target ni nicheni value ni height calculate thai jay chee jena lidhe extra function call karvani jarur nathii khoti
        }

        int left=chalse(root->left,start);
        int right=chalse(root->right,start);
        if(left<0){
            ans=max(ans,abs(left)+right);
            return left-1;
        }
        if(right<0){
            ans=max(ans,left+abs(right));
            return right-1;
        }
        return 1+max(left,right);
     }





    int amountOfTime(TreeNode* root, int start) {
        chalse(root,start);
        return ans;
    }
};
