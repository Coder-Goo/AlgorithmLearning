#include<vector>
using namespace std;

 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//给一颗二叉树的前序遍历和中序遍历，重建该二叉树
 //  1. 前序遍历第一个数为根结点， 并将中序遍历分为左右子树，
 //  2. 根据中序遍历分成的左右子树的个数再分前序遍历分为左子树前序和右子树前序
 //  3. 得到左右子树的前序遍历和中序遍历后重复1,2再递归

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        if(preorder.size() != inorder.size()) throw "array size is not equal";
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        vector<int>left_in(inorder.begin(), it);
        vector<int>right_in(it+1, inorder.end());
        vector<int>left_pre(preorder.begin()+1, preorder.begin()+1+left_in.size());
        vector<int>right_pre(preorder.begin()+1+left_in.size(), preorder.end()); 
        root-> left = buildTree(left_pre, left_in);
        root -> right = buildTree(right_pre, right_in);
        return root;
    }
};