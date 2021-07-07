//思路：二叉树的层序遍历
struct TreeNode {
public:
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x): val(x), left(nullptr),right(nullptr) {}
};

using namespace std;
#include<queue>

//解法： 用对列的层序遍历

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root == nullptr) return {};
        std::queue<TreeNode*>que;
        vector<int> result;
        que.push(root);
        while(!que.empty()) {
            TreeNode* temp = que.front();
            result.push_back(temp -> val);
            que.pop();
            if(temp -> left != nullptr) que.push(temp -> left);
            if(temp -> right != nullptr) que.push(temp -> right);
        }
        return result;
    }
}; 