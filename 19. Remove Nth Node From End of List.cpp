/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * 1 2 3 4 5     5
 * 1 2 3 4
 * 分析：目标是删除一个单链表相对于最后一个节点的目标数的节点
 * 用两个指针去遍历这个链表
 * 这也是一个tow pointers类型的题目
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        int count = 0;
        ListNode* cur = head;
        ListNode* sec = head;
        while(cur) {
        	if(!cur->next) break;
        	if(count == n) {//今天犯了两次的错误 判断等于
        		sec = sec->next;
        	}
        	cur = cur->next;
        	count = count==n?n:count+1;
        }

        if(count==n){//删除的不是头结点
        	ListNode* temp = sec->next;
            sec->next = temp->next;
            return head;
        }
        else {//删除的是头结点
        	return head->next;
        }
    }
};

//思路一样别人的代码更加清晰
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode *first,*second;
        first=head;second=head;
        int i=n;
        while(i--){//先行n步 顺便判断是否是删除了头结点
            second=second->next;
            if(!second)
                return head->next;
        }
        while(second->next){
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return head;
    }
};