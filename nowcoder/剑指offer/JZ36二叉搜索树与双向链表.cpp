//将二叉搜索树改为双向链表
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        inDFS(root);
        head ->left = pre;
        pre -> right = head;
        return head;
        
    }
    //中序遍历每个结点
    //对每个结点的操作，left指向他的左孩子，right指向他的右孩子，

    void inDFS(Node * cur) {

        if(cur == NULL) return;
        inDFS(cur -> left);
        if(pre == NULL) head = cur;
        else pre-> right = cur;
         cur -> left = pre;
         pre = cur;
        inDFS(cur -> right);

    }

private:
    Node * pre , *head;
};

//头结点如何指向尾结点？（如何找到头结点，如何找到尾结点？）声明两个私有成员head和pre
//当pre还没被赋值的时候说明找到了head，一直更新pre，最后一个pre就是尾结点！！！
//每个结点如何改写？ //用pre和head指针来记录前一个结点