/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
就是将奇数id的节点按照顺序放到前面偶数的按顺序放到后面
需要的是o(1)的空间复杂度和O(n)的时间复杂度

 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        if(!head->next->next) return head;
        int id = 0;
        ListNode* pre_odd = head,*cur = head,*pre = head,* even = head->next;
        while(cur) {
        	++id;
        	if(id%2&&id>1) {
        		pre_odd->next = cur;
        		ListNode* next = cur->next;
        		pre->next = next;
        		pre_odd = cur;
        	}
        	else if(id%2==0){
        		pre = cur;
        	}
            cur = cur->next;
        }
        pre_odd->next = even;
        return head;
    }
};