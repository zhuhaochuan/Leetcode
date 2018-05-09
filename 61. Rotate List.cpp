/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：旋转一个单链表k次
 * Input: 1->2->3->4->5->NULL, k = 2
   Output: 4->5->1->2->3->NULL
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        ListNode* cur_head = head,* cur_tail = head,* cur = head;
        int count = 1;
        while(cur->next) {//记录链表总长度 同时得到最后非空节点
        	cur = cur->next;
        	++count;
        }
        k = k%count;//对长度取余

        cur_tail = cur;
        if(k==0)
        	return head;
        cur = head;
        int c =  count - k - 1;
        while(c) {
        	cur = cur->next;
        	--c;
        }
        cur_head = cur->next;
        cur_tail->next = head;
        cur->next = nullptr;
        return cur_head;
    }
};