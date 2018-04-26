/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：将第n到m位的节点逆序，只使用一次遍历
 使用头插法逆序，没次计数加1
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return nullptr;
        int count = n - m + 1,c = 1;
        ListNode* cur = head,*newhead = new ListNode(-1),*pre = newhead,*reverse = newhead,*tag = newhead;
        newhead->next = head;
        while(cur&&count) {
            if(c == m) {
                reverse = pre;
                ++c;
                --count;
                tag = cur;
                pre = cur;
                cur = cur->next;
            }
            else if(c == m + 1) {
                ListNode* temp = cur->next;
                reverse->next = cur;
                cur->next = pre;
                pre = cur;
                cur = temp;
                --count;
            }
            else {
                pre = cur;
                cur = cur->next;
                ++c;
            }
        }
        tag->next = cur;
        return newhead->next;
    }
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head)  return head;
        ListNode* tmp_head = new ListNode(1);
        tmp_head->next = head;

        ListNode* p = tmp_head;

        for(int i=1;i<m;i++)
            p = p->next;
        ListNode* pm = p->next;


        //p是翻转部分前的节点，pm是反转后的尾节点

        for(int i=0;i<(n-m);i++){
            ListNode* tmp = pm->next;
            pm->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        return tmp_head->next;
    }
};