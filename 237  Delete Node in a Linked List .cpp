/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 给出一个节点，只能删除这个节点。
 * 那么就是得到这个节点之后的信息然后将这个节点覆盖，并且将再后面的节点连接到当前节点之后，等价于删除的是下一个节点。
 * 1 2 3 4 5
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        ListNode* next_node = node->next;
        if(next_node) {
        	node->val = next_node->val;
        	node->next = next_node->next;
        }
    }
};