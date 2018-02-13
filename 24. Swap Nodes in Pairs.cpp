/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * l r t
 * r l t
 *     l r
 *我的想法就是 采用两个指针分别指向要交换的两个节点
 *同时还需要两个指针去保存后一个节点的next指针，这样才能够往后延续
 *还需要一个指针去保存交换后的第二个节点 在下一次与后面第一个节点相连接需要
 *不停的循环直到出现空为止。
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* l = head,*r = head->next,*res = r;
        ListNode* temp = NULL,*pre = l;
        while(l&&r) {
        	temp = r->next;
        	r->next = l;
        	l->next = temp;
        	l = temp;
        	r = temp?temp->next:NULL;
            pre->next = r?r:temp;
            pre = l;
        }
        return res;
    }
};

//递归的方法 依次相连
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode* cur = head->next;
        ListNode* nex = cur->next;
        cur->next = head;
        head->next = swapPairs(nex);
        return cur;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        auto last = &dummy;
        while (last->next != NULL) {
            last = swapNext2(last);
        }
        return dummy.next;
    }

    ListNode* swapNext2(ListNode* prev) {
        auto first = prev->next;
        if (first == NULL) {
            return NULL;
        }
        auto second = first->next;
        if (second == NULL) {
            return first;
        }
        auto tail = second->next;
        prev->next = second;
        second->next = first;
        first->next = tail;
        return first;
    }
};



