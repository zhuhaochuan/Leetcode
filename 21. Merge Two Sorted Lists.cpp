/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 将两个已经排好序的链表 合并成一个新的链表
 *
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
    	if(l1->val>l2->val) return mergeTwoLists(l2,l1);//老套路
        if(!l1->next) {
            l1->next = l2;
            return l1;
        }
        ListNode* l = l1, ListNode* r = l1->next, * cur = l2;//指针的连续声明
        while(cur) {
        	while(cur->val>r->val) {
        		l = r;
        		r = r->next;
                if(!r) {
                    l->next = cur;
                    return l1;
                }
        	}
        	l->next = cur;
            ListNode* temp = cur->next;//保存当前节点的下一个节点 在被覆盖之前
        	cur->next = r;//被覆盖
            l = cur;//插入了一个节点 那么l节点将是这个节点
        	cur = temp;
        }
        return l1;
    }
};