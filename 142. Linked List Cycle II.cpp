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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* fast = head,*slow = head;
        while(fast) {
            fast = fast->next?fast->next->next:nullptr;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(!fast) return nullptr;
        while(head) {
            if(head == slow) return slow;
            head = head->next;
            slow = slow->next;
        }
        return nullptr;
    }
};