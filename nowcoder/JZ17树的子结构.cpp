//输入两颗二叉树A,B，判断B是不是A的子结构
//示例
//输入：{8,8，#，9，#，2，#，5}，{8,9，#，2}
//返回值： true

struct TreeNode {
public:
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x): val(x), left(nullptr),right(nullptr) {}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

    }

    //先判断节点值是否相同,如果相同就判断子结构是否相同，如果节点值不同或子结构不同就遍历root1的孩子进行比较
    bool IsEqual(TreeNode* root1, TreeNode * root2) {
        if(root1 == nullptr || root2 == nullptr) return false;
        bool flag = false;
        if(root1 -> val == root2 -> val) {
            flag = Tree1HasTree2(root1, root2);
        }
        if(!flag) {
            return IsEqual(root1 -> left, root2) || IsEqual(root1-> right, root2);
        }
        return flag;
    }

    //判断当前两个节点的子结构是否相同
    bool Tree1HasTree2(TreeNode* tree1, TreeNode* tree2) {
        if(tree1 -> val != tree2 -> val) return false;
        else {
            
        }
    }
};