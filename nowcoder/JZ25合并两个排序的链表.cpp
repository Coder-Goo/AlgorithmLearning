//其实就是归并排序的合并两个数组，建立一个附加数组
//判断两个数组元素的大小，把小的放入附加数组中，如果一个数组已经复制完全，那么就将另一个数组的所有数都复制到附加数组结尾

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* list = new ListNode(0);
        ListNode* cur = list;
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val < l2-> val) {
                cur -> next = l1;
                l1 = l1-> next;
            }else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if(l1 == NULL) {
            while(l2 != NULL) {
                cur->next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
        }else if(l2 == NULL) {
            while(l1 != NULL) {
                cur-> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            }
        }
        return list -> next;
    }
};