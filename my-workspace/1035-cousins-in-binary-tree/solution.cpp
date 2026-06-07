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
   bool parent(TreeNode*root,int x,int y){
    if(root==NULL){
        return 0;
    }
    if(root->left!=NULL && root->right!=NULL){
        if(root->left->val==x && root->right->val==y){
            return 1;
        }
        if(root->left->val==y && root->right->val==x){
            return 1;
        }
    }
    return parent(root->left,x,y) || parent(root->right,x,y);
   }
    bool isCousins(TreeNode* root, int x, int y) {

        if(root==NULL){
            return 0;
        }
       queue<TreeNode*>q;
       q.push(root);
       int l1=-1;
       int l2=-1;
       int level=0;
       while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        TreeNode*temp=q.front();
        q.pop();

        if(temp->val==x){
            l1=level;
        }
        if(temp->val==y){
            l2=level;
        }

        if(temp->left!=NULL){
           q.push(temp->left);
       }
       if(temp->right!=NULL){
        q.push(temp->right);
       }
        }
       level++;
       
       }
       if(l1!=l2){
        return 0;
       }
       return !parent(root,x,y);
    }
};
