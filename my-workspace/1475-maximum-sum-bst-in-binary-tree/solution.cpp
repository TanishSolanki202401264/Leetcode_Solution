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
 class Box{
public:
    bool BST;
    int sum;
    int min;
    int max;

    Box(){
        BST = 1;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }

    Box(int data){
        BST = 1;
        sum = data;
        min = data;
        max = data;
    }
};

Box* find(TreeNode* root, int &maxSum){
    // empty tree
    if(!root){
        return new Box();
    }

    Box* lefthead = find(root->left, maxSum);
    Box* righthead = find(root->right, maxSum);

    // BST condition
    if(lefthead->BST && righthead->BST &&
       lefthead->max < root->val &&
       righthead->min > root->val){

        Box* head = new Box(root->val);
        head->sum = root->val + lefthead->sum + righthead->sum;
        //koi  case ma root no left ke root no right exists na pan karto hoy avuu pan bane atle
        head->min = min(root->val, lefthead->min);
        head->max = max(root->val, righthead->max);

        maxSum = max(maxSum, head->sum);
        return head;
    }
    else{
        // not BST
        lefthead->BST = 0;
        lefthead->sum = max(lefthead->sum, righthead->sum);
        return lefthead;
    }
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        find(root, maxSum);
        return maxSum;
    }
};
