//找到二超搜索树的第k大结点

//二叉搜索树，中序遍历为递增的，那么中序遍历倒序取第k个不就行了

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int count = 0;
        ReverseMid(root,count,k);
        return count;
    }

    //中序遍历的倒序，如果是遍历到第k个，直接返回，不用在继续遍历
    //二叉树的遍历函数的返回值最好是void，因为到达子叶的返回值时，需要返回作为递归终止条件，此时的返回值不好确定
    void ReverseMid(TreeNode* root ,int& count, int& k ) {
        if(root == NULL) return;  
        ReverseMid(root -> right, count , k);
        k--;
        if(k == 0) {
            count =  root -> val;
            return;
        }
        ReverseMid(root -> left,count , k);
    }

};