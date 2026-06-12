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
   void inorder(TreeNode*root,vector<int>&ans){
      if(root==NULL){
          return;
      }
      inorder(root->left,ans);
      ans.push_back(root->val);
      inorder(root->right,ans);
      
  }
    bool findTarget(TreeNode* root, int k) {
         vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
       unordered_set<int> st;
for(int i =0;i < n;i++) {
    int need = k- ans[i];
    if(st.find(need) != st.end()) {
        return true;
    }
    st.insert(ans[i]);
}
return false;
    }
};
