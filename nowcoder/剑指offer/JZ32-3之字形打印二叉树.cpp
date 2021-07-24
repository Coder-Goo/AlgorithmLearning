
用双栈实现

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>result;
        l_stk.push(root);
        bool change = true;
        while(!l_stk.empty() || !r_stk.empty()) {    
            if(change) {
                vector<int>temp_vec;
                while(!l_stk.empty()) {
                    TreeNode* temp = l_stk.top();
                    l_stk.pop();
                    if(temp -> left) r_stk.push(temp -> left);
                    if(temp -> right) r_stk.push(temp -> right);
                    temp_vec.push_back(temp -> val);
                }
                result.push_back(temp_vec);
                change = !change;
            }else {
                vector<int>temp_vec;
                while(!r_stk.empty()) {
                    TreeNode* temp = r_stk.top();
                    r_stk.pop();
                    if(temp -> right) l_stk.push(temp -> right);
                    if(temp -> left) l_stk.push(temp -> left);
                    temp_vec.push_back(temp -> val);
                }
                result.push_back(temp_vec);
                change = !change;
            }
        }
        return result;
    }

private:
    stack<TreeNode*> l_stk, r_stk;
};

