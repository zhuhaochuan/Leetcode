/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：长度为N的链表 每个节点的val都不一样 取值从0-N-1
    空间复杂度为O(G,size()) 时间复杂度为O(m+n)
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head) return 0;
        unordered_map<int,int> table;
        for(int each : G)
            ++table[each];
        ListNode* cur = head->next,* pre = head;
        int res = table[head->val]?1:0;
        while(cur) {
            if(table[cur->val]&&table[pre->val]==0)
                ++res;
            pre = cur;
            cur = cur->next;
        }
        return res;
    }
};