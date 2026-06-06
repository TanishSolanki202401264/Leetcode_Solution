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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>result;
        if(root==NULL){
            return result;
        }

        stack<TreeNode*>s1;//left to right level
        stack<TreeNode*>s2;//right to left level

        s1.push(root);

        while(!s1.empty() || !s2.empty()){
            vector<int>level1;
            while(!s1.empty()){
                TreeNode*temp=s1.top();
                s1.pop();

                level1.push_back(temp->val);
                if(temp->left!=NULL){
                    s2.push(temp->left);
                }
                if(temp->right!=NULL){
                    s2.push(temp->right);
                }
            }
          if(!level1.empty()){
            result.push_back(level1);
          }
           vector<int>level2;

           while(!s2.empty()){
            TreeNode*temp=s2.top();
            s2.pop();

            level2.push_back(temp->val);

            if(temp->right!=NULL){
                s1.push(temp->right);
            }
            if(temp->left!=NULL){
                s1.push(temp->left);
            }
           }
            if(!level2.empty()){
                result.push_back(level2);
            }
           
        }
       return result;
    }
};
