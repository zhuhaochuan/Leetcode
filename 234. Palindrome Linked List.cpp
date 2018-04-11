/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：判断一个单链表是否是回文链表
 1-2-3-3-2-1
 2 1 3 2 1
 1 2 3 4
 1 3 2 4
 1 4 3 2
 */


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        // 1. Find the middle point.
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the 2nd part
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        slow->next = NULL; // set the 1st part
        while (cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            // set for next loop
            pre = cur;
            cur = nxt;
        }
        // While finishing, pre = header of the 2nd part
        // Compare 1st part & 2nd part
        ListNode *l1 = head;
        ListNode *l2 = pre;

        // printListClass(l1);
        // printListClass(l2);

        while (l2){
            if (l2->val != l1->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        // While all comparisons are equal, it is a palindrome.
        return true;
    }
};

