#include<algorithm>
struct TreeNode {
public:
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x): val(x), left(nullptr),right(nullptr) {}
};

//思路：
/*
    二叉树一般都是递归；不能用中序遍历
    递归三要素：终止条件，本层操作，递归
    最重要的是弄清楚递归函数的定义：交换当前结点的左右孩子，并返回当前结点
*/
//前序遍历
TreeNode* Mirror(TreeNode* pRoot) {
    if(pRoot == nullptr) return nullptr;
    TreeNode* temp = pRoot -> left;
    temp = pRoot -> left;
    pRoot -> left = pRoot -> right;
    pRoot -> right = temp;
    pRoot -> right = Mirror(pRoot -> right);
    pRoot -> left =  Mirror(pRoot -> left);
    return pRoot;

}
//后序遍历
//递归函数的定义：交换当前结点的左右子结点的值，并返回当前结点
TreeNode* Mirror(TreeNode* pRoot) {

    if(pRoot == nullptr) return nullptr;

    pRoot -> right = Mirror(pRoot -> right);
    pRoot -> left =  Mirror(pRoot -> left);

    //交换两个变量的值
    std::swap(pRoot -> left, pRoot -> right);

    return pRoot;
}

