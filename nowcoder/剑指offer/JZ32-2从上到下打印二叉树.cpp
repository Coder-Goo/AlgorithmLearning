

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {}; 
        queue<TreeNode*>que;
        que.push(root);
        int size = 0;
        vector<vector<int>>result;
        TreeNode* temp = NULL;
        while(!que.empty()) {
            vector<int>temp_vec;
            size = que.size();
            for(int i = 0; i< size; i++) {
                temp = que.front();
                que.pop();
                temp_vec.push_back(temp->val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp-> right);
            }
            result.push_back(temp_vec);
        }
        return result;
    }
};