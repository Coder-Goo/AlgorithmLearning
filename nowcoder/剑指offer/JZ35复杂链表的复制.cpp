/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* new_head = new Node(head -> val);
        Node* result = new_head;
        Node* cur = head;
        //先得到next指针链表
        while(cur-> next != NULL) {
            Node* temp = cur -> next;
            new_head ->next =  new Node(temp -> val);
            cur = temp;
            new_head = new_head -> next;
        }
        //再复制random指针集合
        new_head = result;
        while(head != NULL) {
            if(head -> random == NULL) {
                new_head->random = NULL;
            } else {
                Node* temp = head -> random;
                //从头开始遍历，
                Node* new_temp = result;
                while(new_temp -> val != temp -> val ) { //这里光靠值相等来判断是否是正确的结点是不够的，相同的值会导致错误
                    new_temp = new_temp -> next;
                }
                new_head -> random = new_temp;
            }
            new_head = new_head -> next;
            head = head -> next;
        }
        return result;
    }
};

//下面是使用哈希表的正确解法
//使用哈希表进行复制
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
};


//方法二：
//拼接方法：构建原结点->新结点->原结点->新结点...的新链表，那么找到原结点node，那么node-> next 就是新结点，实现定位
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node*cur = head;
        Node* temp = NULL;
        //构造原——>新——>原->新...的链表
        while(cur != NULL) {
            temp = new Node(cur -> val);
            temp -> next = cur -> next;
            cur -> next = temp;
            cur = temp-> next;
        }
        //复制random指针
        cur= head;
        while(cur != NULL) {
            temp = cur -> next ;
            if(cur -> random  == NULL) {
                temp -> random = NULL;
                cur = temp -> next;
                continue;
            }
            temp-> random = cur -> random -> next;
            cur = temp -> next;
        }

        //拆分新数组！！发生原链表被修改的错误，借鉴的K神的
        cur = head->next;
        Node* pre = head, *res = head->next;
        while(cur->next != nullptr) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr; // 单独处理原链表尾节点
        return res;

        //一开始最后拆分数组写的是这个，发生错误，提示原链表被修改
        //问题出在没有将修改后的原链表改回去！！！！
        // cur = head;
        // Node * copy_list = cur -> next ;
        // while(cur != NULL) {
        //     temp = cur -> next;
        //     cur = temp -> next;
        //     if(cur != NULL) temp -> next = cur -> next;
        //     else temp-> next = NULL;
        // }
        // return copy_list;

    }
};