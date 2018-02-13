/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 给定一个小于等于链表总长度的值
 * 以这个长度为一组对于给定的链表按组逆序
 * 不能改变节点的值只能改变节点的连接顺序
 *
 * 我的想法是将整个链表拆分成一组一组
 * 使用递归的方式处理再相连接
 * 每一组内部其实就是一个链表的逆序
 * 采用栈的方式进行链表逆序
 * 这里注意使用栈的方式翻转链表在空间上需要O(n)的开销
 * 采用指针不断循环翻转的方式空间消耗会小 为常数
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        if(k==1) return head;
        ListNode* res = NULL,*tail = head,*cur = NULL;
        stack<ListNode*> s; s.push(tail);
        int count = k;
        while(count>1) {
        	tail = tail->next;
            s.push(tail);
            if(!tail) return head;
        	--count;
        }
        tail = tail->next;
        res = s.top();
        cur = res;
        s.pop();
        while(!s.empty()) {
        	cur->next = s.top();
            cur = s.top();
        	s.pop();
        }
        cur->next = reverseKGroup(tail,k);
        return res;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* rev;
        int tmp = k - 1;
        int i;
        for (i=0;i<k;i++) {
        	if (node == NULL) {
        		return head;
        	}
        	node = node->next;
        }
        rev = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return rev;
    }

    ListNode * reverse(ListNode *start, ListNode *end) {
        ListNode *prev = end;
        ListNode *next;
        while (start != end) {
            next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* h = head;
        int len = 0;
        ListNode l(0);
        l.next = head;
        ListNode* pre = &l;

        while (h) {
            h = h->next;
            len++;
        }
        int n = len/k;
        h = head;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k; j++) {
                ListNode* next = h->next;
                ListNode* nextnext = h->next->next;
                next->next = pre->next;
                pre->next = next;
                h->next = nextnext;
            }
            pre = h;
            h = h->next;
        }
        return l.next;
    }
};