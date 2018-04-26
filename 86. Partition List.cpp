/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next) return head;
        ListNode*cur = head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead,*res = new ListNode(0),*lower = res;
        while(cur) {
            if(cur->val<x) {
                lower->next = new ListNode(cur->val);
                lower = lower->next;
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        lower->next = newhead->next;
        return res->next;
    }
};


//稍作改进 不使用多余空间
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next) return head;
        ListNode*cur = head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* pre = newhead,*res = new ListNode(0),*lower = res;
        while(cur) {
            if(cur->val<x) {
                pre->next = cur->next;
                lower->next = cur;
                lower = lower->next;
                cur = cur->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        lower->next = newhead->next;
        return res->next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLeft = new ListNode(-1);
        ListNode* dummyRight = new ListNode(-1);
        ListNode* leftCur = dummyLeft;
        ListNode* rightCur = dummyRight;
        while(head != nullptr){
            if(head->val < x){
                leftCur->next=head;
                leftCur=leftCur->next;
            }
            else{
                rightCur->next=head;
                rightCur=rightCur->next;
            }
            head=head->next;
        }
        leftCur->next=dummyRight->next;
        rightCur->next=nullptr;             //Very important line
        return dummyLeft->next;

    }
};