class Solution {
public:

    int find(vector<int>& postorder, int target, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(postorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* Tree(vector<int>& preorder, vector<int>& postorder,
                   int Prestart, int Preend,
                   int Poststart, int Postend) {

        if(Prestart > Preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[Prestart]);

        if(Prestart == Preend) {
            return root;
        }

        int leftRoot = preorder[Prestart + 1];

        int pos = find(postorder, leftRoot, Poststart, Postend);

        int leftSize = pos - Poststart + 1;

        root->left = Tree(preorder, postorder,
                          Prestart + 1,
                          Prestart + leftSize,
                          Poststart,
                          pos);

        root->right = Tree(preorder, postorder,
                           Prestart + leftSize + 1,
                           Preend,
                           pos + 1,
                           Postend - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        return Tree(preorder, postorder,
                    0, n - 1,
                    0, n - 1);
    }
};
