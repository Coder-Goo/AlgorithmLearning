#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

//εεΊιε
class Solution {
public:
    vector<int> result;
    vector<int> reversePrint(ListNode* head) {
        ReversePrint(head);
        return result; 
    }
    void ReversePrint(ListNode* root) {
        if(root == nullptr) return;
        ReversePrint(root -> next);
        result.push_back(root -> val);
    }
};