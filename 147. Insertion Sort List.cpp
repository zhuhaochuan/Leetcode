/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };实现单链表的插入排序
 */
//我的方法 每次都是从头找到该插入的位置进行插入
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* cur = head,* pre = head,* max = head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;

        while(cur) {
            if(cur->val>=max->val)
                max = cur;
            if(cur->val>=pre->val) {
                if(pre!=cur) pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
            else if(cur->val<pre->val){
                ListNode* temp = newhead->next,*p = newhead,* next = cur->next;
                while(temp) {
                    if(temp->val>=cur->val) {
                        p->next = cur;
                        cur->next = temp;
                        break;
                    }
                    else {
                        p = temp;
                        temp = temp->next;
                    }
                }
                cur = next;
            }
        }
        max->next = nullptr;
        return newhead->next;
    }
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> A;
        ListNode* node = head;
        while (node) {
            A.push_back(node->val);
            node = node->next;
        }
        sort(A.begin(), A.end());
        node = head;
        for (int i = 0; i < A.size(); i++) {
            node->val = A[i];
            node = node->next;
        }
        return head;
    }
};