/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：判断一个单链表是否含有环
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* first = head,* second = head;
        while(first&&first->next) {
        	first = first->next->next;
        	second = second->next;
        	if(first==second)
        		return true;
            if(first==head)
                return true;
        }
        return false;
    }
};