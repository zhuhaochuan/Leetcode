/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：删除有序单链表中的重复节点
 * 1 2 2 3
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* cur = head->next,* pre = head;
        while(cur) {
        	if(cur->val==pre->val) {
        		pre->next = cur->next;
        		cur = cur->next;
        	}
        	else {
        		pre = cur;
        		cur = cur->next;
        	}
        }
        return head;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};