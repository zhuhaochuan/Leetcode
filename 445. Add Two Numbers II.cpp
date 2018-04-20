/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：将两个单链表代表的数合并 形成一个新的单链表
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output: 7 -> 8 -> 0 -> 7
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1||l1->val==0) return l2;
        if(!l2||l2->val==0) return l1;
        vector<int> v1,v2;
        ListNode* cur1 = l1,*cur2 = l2;
        while(cur1||cur2) {
        	if(cur1) {
	        	v1.push_back(cur1->val);
	        	cur1 = cur1->next;
	        }
	        if(cur2) {
	        	v2.push_back(cur2->val);
	        	cur2 = cur2->next;
        	}
        }
        int n1 = v1.size()-1,n2 = v2.size()-1,c = 0;
        ListNode* pre = NULL,*cur = NULL;
        while(n1>=0||n2>=0||c) {
        	int a = n1>=0?v1[n1]:0;
        	int b = n2>=0?v2[n2]:0;
        	int temp = (a + b + c)%10;
        	cur = new ListNode(temp);
        	cur->next = pre;
        	pre = cur;
        	c = (a + b + c)/10;
        	--n1;
        	--n2;
        }
        return cur;
    }
};