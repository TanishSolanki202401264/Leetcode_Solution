class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left != NULL) {
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right != NULL) {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int dist = 0;

        while(!q.empty()) {
            int n = q.size();

            if(dist == k) {
                break;
            }

            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != NULL && !visited[temp->left]) {
                    visited[temp->left] = true;
                    q.push(temp->left);
                }

                if(temp->right != NULL && !visited[temp->right]) {
                    visited[temp->right] = true;
                    q.push(temp->right);
                }

                if(parent.count(temp) && !visited[parent[temp]]) {
                    visited[parent[temp]] = true;
                    q.push(parent[temp]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
