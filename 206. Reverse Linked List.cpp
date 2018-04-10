/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 分析：反转一个单链表
 * 1-2-3-4-5
 *
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        stack<ListNode*> s;
        ListNode* cur = head;
        while(cur) {
        	s.push(cur);
        	cur = cur->next;
        }
        ListNode* res = s.top();
        cur = res;
        s.pop();
        while(!s.empty()) {
        	cur->next = s.top();
        	s.pop();
        	cur = cur->next;
        }
        cur->next = NULL;
        return res;
    }
};

//构建一个头结点每到一个节点将其插在之前连接的节点的前面
//注意需要一个temp指针保存被插入的节点的next指针以防止断掉连接
//这样只需要常数的空间
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return new_head -> next;
    }
};