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
  
  int find(vector<int>&inorder,int target,int start,int end){
      for(int i=start;i<=end;i++){
          if(inorder[i]==target){
              return i;
          }
         
      }
      return -1;
  }
    
    TreeNode*Tree(vector<int>&inorder,vector<int>&preorder,int Instart,int Inend,int index){
        if(Instart>Inend){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[index]);
        int pos=find(inorder,preorder[index],Instart,Inend);
        //pos apane find karine apse ke kaya thii kaya sudhii na element ne kya nakhavana apde
        
        root->left=Tree(inorder,preorder,Instart,pos-1,index+1);
        //left side start thii pos-1 sudhii javanu and right side pos+1 thii end sudhii javanu
        root->right=Tree(inorder,preorder,pos+1,Inend,index+(pos-Instart)+1);
         return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
          int n=inorder.size();
     return  Tree(inorder,preorder,0,n-1,0);
        
    }
};*/
class Solution {
public:

    int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* Tree(vector<int>& inorder, vector<int>& preorder,
                   int Instart, int Inend, int index) {

        if (Instart > Inend || index >= preorder.size())
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int pos = find(inorder, preorder[index], Instart, Inend);
        int leftSize = pos - Instart;

        root->left = Tree(inorder, preorder,
                          Instart, pos - 1,
                          index + 1);

        root->right = Tree(inorder, preorder,
                           pos + 1, Inend,
                           index + leftSize + 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Tree(inorder, preorder, 0, inorder.size() - 1, 0);
    }
};

