class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        this-> count = 0;
        this -> target = target; 
        vector<int>vec;
        BackTrace(root,vec );
        return result;
    }
     void BackTrace(TreeNode* root, vector<int>&temp_vec) {
        if(root == NULL) return ;
        //收集结果
        count += root -> val;
        temp_vec.push_back(root -> val);

        //满足条件收集结果
        if(!root -> left && !root -> right && count == target) {   //其实不用计算count的值，而是应该target-root->val
            result.push_back(temp_vec);
            //这里没有return了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
        }

        BackTrace(root -> left,temp_vec);
        BackTrace(root -> right, temp_vec);

        //回溯退出是对 本层的结果回退，所以应该放这
        temp_vec.pop_back();
        count -= root -> val;

    }

private:
    int count, target;
    vector<vector<int>> result;
};

//第一次写的， 回溯算法结果发生重复，回溯函数如下：
//原因：终止条件没有弄好
void BackTrace(TreeNode* root, vector<int>&temp_vec) {
        //收集结果
        if(count == target && root == NULL) {
            result.push_back(temp_vec);
            return;
        } else if( root == NULL) return;


        count += root -> val;
        temp_vec.push_back(root -> val);

        BackTrace(root -> left,temp_vec);
        BackTrace(root -> right, temp_vec);

        temp_vec.pop_back();
        count -= root -> val;

    }



//二：一开始的回溯逻辑写的是这个！！！！出现两个问题：回溯回来的时候没有对count进行减操作，只对vec进行了pop()操作
//第二个问题：回溯丢弃结果的位置不对
        count += root -> val;
        temp_vec.push_back(root -> val);
        //进入下一层
        BackTrace(root -> left,temp_vec);
        //回溯清除结果
        temp_vec.pop_back();
        //进入下一层
        BackTrace(root -> right, temp_vec);