将二叉树序列化为字符串，再将字符串反序列化为二叉树
1. 双向队列，删除元素deque.erase(p)；  //p需要是迭代器
2. 将字符串按','分为一个个小字符串存到双向队列中叶值得学习

```__cpp
class Codec {
public:

    // Encodes a tree to a single string.

    //递归函数的定义：返回当前结点之后的序列化
    string serialize(TreeNode* root) {
        if(root== NULL) {  
            return "NULL";
        }
        string temp = to_string(root -> val);
        temp += ",";
        temp += serialize(root ->left);
        temp +=",";
        temp += serialize(root -> right);
        return temp;
    }

//*************************************************下面是反序列化**************************

    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        string str;
        for(char ch: data) {
            if(ch == ',') {
                dq.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        //只有一个元素的情况
        if(!str.empty()) {
            dq.push_back(str);
        }
        return rserialize();
    }

    //递归函数的定义：返回dp中font()元素做成的结点
    TreeNode* rserialize(){
            if(dq.front() =="NULL") {
                dq.erase(dq.begin());
                return NULL;
            }
            TreeNode* root = new TreeNode(stoi(dq.front()));
            dq.erase(dq.begin());
            root -> left = rserialize();
            root -> right = rserialize();
            return root;
    }

private:
    deque<string>dq;
};
```