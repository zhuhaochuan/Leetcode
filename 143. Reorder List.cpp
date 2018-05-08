/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析；将一个单链表改变成要求的顺序
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 *  L0→Ln→L1→Ln-1→L2→Ln-2→…
 */
//o(n)的时间和空间复杂度
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next) return;
        stack<ListNode*> s;
        ListNode* cur = head;
        int count = 0;
        while(cur) {
        	++count;
        	s.push(cur);
        	cur = cur->next;
        }
        count = count / 2;
        cur = head;
        while(count) {
        	ListNode* temp = cur->next;
        	cur->next = s.top();
        	s.pop();
        	cur->next->next = temp;
        	cur = temp;
        	--count;
        }
        cur->next = nullptr;//最后需要截断
    	return;
    }
};

//思路：先使用快慢指针将链表从中间分割成两段，然后后半段就地逆置．之后合并插入到前半段链表即可，时间复杂度O(n)空间复杂度为o(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head, *p=head, *q=head;
        while(fast->next && fast->next->next)
            slow = slow->next, fast = fast->next->next;
        fast = slow->next, slow->next = NULL;
        p = fast, q = fast->next, fast->next = NULL;
        while(q)
        {
            auto tem = q->next;
            q->next = p;
            p = q, q = tem;
        }
        q = head;
        while(q && p)
        {
            auto tem1 = q->next, tem2 = p->next;
            p->next = q->next;
            q->next = p;
            q = tem1, p = tem2;
        }
    }
};