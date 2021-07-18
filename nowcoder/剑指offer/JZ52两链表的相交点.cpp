?/找到两个链表的角点
//A +C +B = B+C+A
//C为公共部分

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr_A = headA;
        ListNode* ptr_B = headB;
        while(ptr_A != ptr_B) {
            if(ptr_A != NULL) ptr_A = ptr_A -> next;
            else ptr_A = headB;
            if(ptr_B != NULL)ptr_B = ptr_B -> next;
            else ptr_B = headA;
        }
        return ptr_A == NULL ? NULL: ptr_A;
    }
};