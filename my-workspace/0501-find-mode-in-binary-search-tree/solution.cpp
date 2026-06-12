class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        unordered_map<int, int> mp;
        for(int x : ans) {
            mp[x]++;
        }
        int freq = 0;
        for(auto it : mp) {
            freq = max(freq, it.second);
        }
        vector<int> result;
        for(auto it : mp) {
            if(it.second == freq) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};
