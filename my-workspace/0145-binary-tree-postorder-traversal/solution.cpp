class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = NULL;

        while(curr != NULL || !st.empty()) {

            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {

                TreeNode* node = st.top();

                if(node->right != NULL &&
                   lastVisited != node->right) {

                    curr = node->right;
                }
                else {

                    ans.push_back(node->val);

                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};
