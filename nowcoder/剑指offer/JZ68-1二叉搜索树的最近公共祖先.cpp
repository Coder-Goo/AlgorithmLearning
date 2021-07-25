
给定一棵二叉搜索树，两个子结点，求取最近的公共祖先

二叉搜索树，，

如果这两个结点都小于当前结点，那么就位于左子树
都大于，位于右子树
如果一个大于，一个小于当前结点，那么当前结点就是公共祖先

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root -> val >= p->val && root -> val <= q ->val) || (root -> val <= p->val && root -> val >= q ->val)) 
        return root;
        else if((root -> val > p->val && root -> val > q ->val))
        return lowestCommonAncestor(root -> left,p,q );
        else return lowestCommonAncestor(root -> right,p,q);
    }
};