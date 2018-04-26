class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* cur = head,*newhead = new ListNode(-1),*pre = newhead,*tail = newhead;
        newhead->next = head;
        int tag = -head->val+1;
        while(cur) {
            if(cur->val!=tag&&(!cur->next||cur->next->val!=cur->val)) {
                pre->next = cur;
                pre = cur;
                tail = cur;
                tag = cur->val;
                cur = cur->next;
            }
            else {
                tag = cur->val;
                cur = cur->next;
            }
        }
        tail->next = nullptr;
        return newhead->next;
    }
};


class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;

        while(head->next && head->next->next){
            if(head->next->val == head->next->next->val){
                int val = head->next->val;
                while(head->next && head->next->val == val){
                    head->next = head->next->next;
                }
            }else{
                head = head->next;
            }
        }
        return dummy.next;
    }
};