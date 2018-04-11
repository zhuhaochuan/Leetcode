/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *分析：找到两个单链表的交集头结点
 *如果没有交集返回空
 *o(n)的时间复杂度o(1)的空间复杂度
 *没想出来：
 *别人的思路非常的好。。两个链表的长度不一定一致，并且我们只能往一个方向去走，不能回头
 *我们没办法得知目前到达了哪一步，也不能改变原始链表的结构
 *所以如果将两个链表逻辑上连接起来A-B和B-A这两个链表长度一致并且必然在最后都是相交部分
 *这样就能够找到交集头结点
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL;
        ListNode* A = headA,* B = headB;
        while(A!=B) {
        	if(!A->next&&!B->next) return NULL;
        	A = A->next?A->next:headB;
        	B = B->next?B->next:headA;
        }
        if(A)
        	return A;
        else return NULL;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};