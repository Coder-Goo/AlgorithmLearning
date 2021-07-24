
//一开始想的是层序比遍历呢，没想到递归这么简单！！！！！！

class Solution {
public:
    //递归函数的定义：输入一个颗树，得到树的深度
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        //树的深度= 1+ 左右子树的高度
        return max(1+maxDepth(root-> left), 1+maxDepth(root -> right));
    }
};