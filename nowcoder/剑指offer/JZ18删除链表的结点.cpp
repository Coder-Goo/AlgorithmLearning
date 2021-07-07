/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre_head = new ListNode(0);
        ListNode* cur = head;
        if(head -> val == val) return head -> next;
        while(cur -> next != NULL && cur -> next -> val != val) {
            cur = cur -> next;
        }
        if(cur-> next == NULL && cur -> val == val) return NULL;
        else if (cur -> next ==  NULL) return head;
        cur -> next = cur -> next -> next;
        return head;
    }
};