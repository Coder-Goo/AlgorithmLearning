最好先看反转区间内的链表！！！
给你一个链表，每隔k个将其反转，结尾不够k个的不用反转
如 [1,2, 3,4, 5] 当k =2时；   [2,1, 4,3, 5]


1. 链表题一般设置虚拟头结点！！
2. 用指针->解引用操作结点完成反转，因此局部反转也不需要返回值


```cpp
class Solution {
    //翻转闭区间
    void Reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* temp = cur -> next;
            cur-> next = pre;
            pre = cur;
            cur = temp;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* dummy_head = new ListNode(0);  //一般设置虚拟头结点
       dummy_head->next = head;
       ListNode* left_pre= dummy_head;
       ListNode* left = new ListNode(0);
       ListNode* right=new ListNode(0);
       ListNode* next=new ListNode(0);
       while(left_pre->next != nullptr) {
           left = left_pre -> next;
           right = left;
           bool flag = false;
           for(int i =1; i<k; i++) {
               right = right -> next;
               if(right == nullptr) {
                   flag = true;
                   break;
               }
           }
           if(flag) break;
           next = right -> next;

           left_pre -> next = nullptr;
           right -> next = nullptr;
           Reverse(left);
           left_pre->next = right;
           left -> next = next;
           left_pre = left;
       }
       return dummy_head -> next;
    }   
};

```