/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：使用O(nlogn)时间复杂度排序一个单链表 常数空间
 * 对于数组来说这样的时间复杂度一般是快速排序
 * 3-2-1-7
 *
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* mid = findmid(head);
        ListNode* head1 = sortList(head);//递归二分链表
        ListNode* head2 = sortList(mid);
        return merge(head1,head2);
    }
    ListNode* findmid(ListNode* head) {
    	ListNode* fast = head,*slow = head,*pre = head;
    	while(fast) {
    		pre = slow;
    		slow = slow->next;
    		fast = fast->next?fast->next->next:nullptr;
    	}
    	pre->next = nullptr;//需要截断链表彻底一分为2
    	return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2) {
    	ListNode* cur1 = head1,*cur2 = head2,* newhead = new ListNode(0),*cur = newhead;
    	while(cur1&&cur2) {
    		if(cur1->val<=cur2->val) {
    			cur->next = cur1;
    			cur1 = cur1->next;
    		}
    		else {
    			cur->next = cur2;
    			cur2 = cur2->next;
    		}
    		cur = cur->next;
    	}
    	cur->next = cur1?cur1:cur2;
    	return newhead->next;
    }
};



class Solution {
public:
    static bool cmp(ListNode* a, ListNode* b) {
            return a->val < b->val;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        vector<ListNode*> nodes;
        ListNode* p = head;
        while (p != nullptr) {
            nodes.emplace_back(p);
            p = p->next;
        }

        sort(nodes.begin(), nodes.end(), cmp);

        p = nodes[0];
        for (int i = 1; i != nodes.size(); ++i) {

            p->next = nodes[i];
            p = p->next;
        }
        p->next = nullptr;
        return nodes[0];

    }
};