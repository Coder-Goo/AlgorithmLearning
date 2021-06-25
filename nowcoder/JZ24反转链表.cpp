
//迭代法：
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = NULL;
//         ListNode* pre_head = NULL;
//         ListNode* cur = head;
//         while(cur != NULL) {                             //判断条件这里出错
//             temp = cur -> next;
//             cur -> next = pre_head;
//             pre_head = cur;
//             cur = temp;
//         }
//         return pre_head;
//     }
// };


// //递归法：
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         return reverse(NULL, head);
//     }

// //递归函数的定义： 反转两个节点,返回反转后的头结点
//     ListNode* reverse(ListNode* pre, ListNode* cur) {
//         if( cur ==  NULL) return pre;
//         ListNode* temp = cur -> next;
//         cur -> next = pre;
//         return reverse(cur, temp);
//     }
// };


//递归方法二：
class Solution {
public:
    //递归函数的定义：反转以head为头结点的链表，并返回反转后的头结点

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode * last = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return last;
    }

};

//递归方法二的图解：
