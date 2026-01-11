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
void find(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
         if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        queue<TreeNode*> q;
        queue<int> index;

        q.push(root);
        index.push(0);

        while (!q.empty()) {
            TreeNode* temp = q.front(); q.pop();
            int pos = index.front(); index.pop();

            if (pos >= 0)
                positive[pos].push_back(temp->val);
            else
                negative[-pos].push_back(temp->val);

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
            }
        }

        vector<vector<int>> result;

        // negative side (left to right)
        for (int i = negative.size() - 1; i >= 1; i--)
            result.push_back(negative[i]);

        // zero and positive side
        for (int i = 0; i < positive.size(); i++)
            result.push_back(positive[i]);

        return result;
    }
};*/
//without row and column sorting
class Solution {
public:
    void find(TreeNode* root, int pos, int &l, int &r) {
        if (!root) return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<pair<int,int>>> positive(r + 1);
        vector<vector<pair<int,int>>> negative(abs(l) + 1);

        queue<TreeNode*> q;
        queue<int> index;
        queue<int> row;

        q.push(root);
        index.push(0);
        row.push(0);

        while (!q.empty()) {
            TreeNode* temp = q.front(); q.pop();
            int pos = index.front(); index.pop();
            int rrow = row.front(); row.pop();

            if (pos >= 0)
                positive[pos].push_back({rrow, temp->val});
            else
                negative[-pos].push_back({rrow, temp->val});

            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
                row.push(rrow + 1);
            }
            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1);
                row.push(rrow + 1);
            }
        }

        // sort each column
        for (auto &v : negative)
            sort(v.begin(), v.end());

        for (auto &v : positive)
            sort(v.begin(), v.end());

        vector<vector<int>> result;

        // negative side (left to right)
        for (int i = negative.size() - 1; i >= 1; i--) {
            vector<int> col;
            for (auto &p : negative[i])
                col.push_back(p.second);
            result.push_back(col);
        }

        // zero and positive side
        for (int i = 0; i < positive.size(); i++) {
            vector<int> col;
            for (auto &p : positive[i])
                col.push_back(p.second);
            result.push_back(col);
        }

        return result;
    }
};

