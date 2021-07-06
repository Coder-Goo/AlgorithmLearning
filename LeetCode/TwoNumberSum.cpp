//两链表，如果和超过10，则考虑进位
//一个链表长，一个链表短，则短的补0；
//如果链表结束还有进位，那么还得增加一个节点来存储进位值
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1== NULL) return l2;
        if(l2 == NULL) return l1;

        int farward = 0;
        ListNode *head = new ListNode();
        ListNode* tail = head;
        while(l1 || l2) {
            int n1 = l1? l1-> val:0;
            int n2 = l2? l2-> val:0;
            int i = n1 + n2 + farward;
            farward = i >= 10? 1:0;
            tail -> next =new ListNode(i%10);
            if(l1 != NULL)l1 = l1 -> next;
            else l1 = NULL;
            if(l2 != NULL)l2 = l2 -> next;
            else l2 = NULL;
            tail = tail -> next;
        }
        if(farward == 1) {
            tail-> next = new ListNode(1);
            tail -> next -> next = NULL;
        }
        return head-> next;
    }
};