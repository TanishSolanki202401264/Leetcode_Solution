class Solution {
public:
    unordered_map<int, TreeNode*> mp;
    bool valid = true;

    TreeNode* dfs(TreeNode* root, long long low, long long high) {
        if(root == NULL) return NULL;

        if(root->val <= low || root->val >= high) {
            valid = false;
            return root;
        }

        if(root->left == NULL && root->right == NULL && mp.count(root->val)) {
            TreeNode* temp = mp[root->val];

            root->left = temp->left;
            root->right = temp->right;

            mp.erase(root->val);
        }

        root->left = dfs(root->left, low, root->val);
        root->right = dfs(root->right, root->val, high);

        return root;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaf;

        for(auto t : trees) {
            mp[t->val] = t;

            if(t->left) leaf.insert(t->left->val);
            if(t->right) leaf.insert(t->right->val);
        }

        TreeNode* root = NULL;

        for(auto t : trees) {
            if(leaf.count(t->val) == 0) {
                if(root != NULL) return NULL;
                root = t;
            }
        }

        if(root == NULL) return NULL;

        mp.erase(root->val);

        dfs(root, LLONG_MIN, LLONG_MAX);

        if(valid == false) return NULL;

        if(mp.size() != 0) return NULL;

        return root;
    }
};
