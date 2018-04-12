/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：删除单链表当中的指定val节点
 *直接遍历
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* cur = head,* pre = head;
        //第一个while寻找链表当中第一个不为val的节点，该节点才是最后需要返回的头结点
        while(cur) {
        	if(cur->val!=val) {
        		pre = cur;
        		break;
        	}
        	else cur = cur->next;
        }
        //如果原链表所有的元素都是需要被删除的val那么得到的cur为空这个时候直接返回空
        if(!cur) return NULL;
        //如果找到了存在的正真头结点往后遍历找到一个目标节点就将其pre的next链入cur->next
        head = pre;
        cur = pre->next;
        while(cur) {
        	if(cur->val==val) {
        		pre->next = cur->next;
        		cur = cur->next;
        	}
        	else {
        		pre = cur;
        		cur = cur->next;
        	}
        }
        return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode * newHead = new ListNode(0);//建立一个新的头结点 这样就解决了头结点本身就是要删除的元素的情况
        newHead->next = head;
        ListNode* cur = newHead;
        while(cur ){
            while( cur->next && cur->next->val == val ){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return newHead->next;
    }
};