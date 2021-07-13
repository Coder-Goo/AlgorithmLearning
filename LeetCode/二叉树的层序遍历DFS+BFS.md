 // 二叉树的层序遍历使用BFS
```cpp
vector<vector<int>> BFS(TreeNode* root) {
    if(root == nullptr) return {};
    queue<TreeNode*> que;
    que.push(root);
    TreeNode* temp = new TreeNode();
    vector<vector<int>> result;
    while(!que.empty()) {
        vector<int> temp_vec;
        int size = que.size();
        for(int i= 0; i<size; i++) {
            temp = que.front();
            que.pop();
            temp_vec.push_back(temp->val);
            if(temp-> left) que.push(temp-> left);
            if(temp-> right) que.push(temp -> right);
        }
        result.push_back(temp_vec);
    }
    return result;
}
```

二叉树的层序遍历： DFS  : **用一个level来标记位于第几层**
```cpp

vector<vector<int>>LevelOrfer(TreeNode* root) {
    vector<vector<int>> result;
    DFS(root, 0, result);
    return result;
}

void DFS(TreeNode* root, int level, vector<vector<int>>& result) {
        if(root == nullptr) return;
        if(level >= result.size()) result.resize(level+1);

        result[level].push_back(root -> val);
        DFS(root -> left, level+1, result);
        DFS(root -> right, level +1, result);
    } 

```