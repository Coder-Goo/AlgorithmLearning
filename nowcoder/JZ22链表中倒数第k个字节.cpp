//快慢指针，快指针先走k步
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* low = head;
        for(int i = 0; i < k; i++) {
            if(fast == NULL) return NULL;
            fast = fast -> next;
        }
        while(fast != NULL) {
            fast= fast -> next;
            low = low -> next;
        }
        return low;
    } 
};