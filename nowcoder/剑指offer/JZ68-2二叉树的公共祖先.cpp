
这一题不一样了，不是二叉搜索树了，如何查看最近公共祖先？

二叉树： 用递归！！

递归函数的定义：  左右子树是否包含这两个节点

class Solution {
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!IsConclude(root ,p, q)) return NULL;
        else return ans;

    }
    //递归函数的定义： 左右子树是否有p,q?
    bool IsConclude(TreeNode* root , TreeNode *p, TreeNode* q) {
        if(root == NULL) return false;
        bool left_son = IsConclude(root ->left , p, q);
        bool right_son = IsConclude(root -> right, p, q);
        if((left_son && right_son)|| (root -> val == p -> val || root -> val == q -> val)&&(left_son || right_son))
        ans = root;
        return left_son || right_son||((root -> val == p -> val )||(root -> val == q-> val));
    }
};

使用哈希表：

class Solution {
    unordered_map<TreeNode*, TreeNode*> my_map;
    unordered_set<TreeNode*>my_set;
public:
    //分别记录每个结点的父结点
    void DFS(TreeNode * root) {
        if(root == NULL) return;
        if(root-> left) {
            my_map[root->left] = root ;
            DFS(root -> left);
        }
        if(root -> right) {
            my_map[root -> right] = root;
            DFS(root -> right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root , TreeNode *p, TreeNode* q) {
        DFS(root);
        my_map[root] = NULL; //!!!!!!!!!!这个很重要！！

        //p向上走，直到root,并把沿途的结点加入进行记录
        while(p != NULL) {   
            my_set.insert(p);
            TreeNode* dad = my_map[p];
            p = dad;
        }

        //q也往上走，判断当前结点在不在set里，如果在，那么该结点就是目标结点
        if(my_set.find(q) != my_set.end()) return q; //判断q本身是不是父结点
        //判断q的父结点
        while(q != NULL) {
            if(my_set.find(my_map[q])!= my_set.end()) return my_map[q];
            else q = my_map[q];
        }
        return NULL;
    }
};