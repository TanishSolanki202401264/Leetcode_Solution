class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        vector<TreeNode*> node(100001, NULL);
        vector<bool> isChild(100001, false);

        for(auto &d : descriptions) {

            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if(node[parent] == NULL) {
                node[parent] = new TreeNode(parent);
            }

            if(node[child] == NULL) {
                node[child] = new TreeNode(child);
            }

            if(isLeft == 1) {
                node[parent]->left = node[child];
            }
            else {
                node[parent]->right = node[child];
            }

            isChild[child] = true;
        }

        for(auto &d : descriptions) {

            int parent = d[0];

            if(isChild[parent] == false) {
                return node[parent];
            }
        }

        return NULL;
    }
};
