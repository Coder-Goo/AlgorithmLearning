
//得先计算树的高度！！！！！


class Solution {
public:
    //判断二叉树是否是 平衡树？
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool balance = abs(height(root->left)-height(root->right)) <=1 ? true:false;
        return  balance && isBalanced(root->left)&& isBalanced(root -> right);
    }

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        return max(height(root->left)+1, height(root->right)+1);
    }
};