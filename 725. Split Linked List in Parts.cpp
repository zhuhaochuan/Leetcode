/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };分析：将一个单链表拆分成若干个子链表 每个链表的长度 最多差1
 * 按照原始的顺序 依次划分 长度长的在前面
 *
 */

//第一版  时间居然击败100%。。。。。debug了半天。。。
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int len = 0,first = 0;
       vector<ListNode*> list;
       ListNode* cur = root;
       while(cur) {
       	list.push_back(cur);
       	++len;
       	cur = cur->next;
       }
       int count = 0, id = 0;
       if(len<=k)
           first = len = 1;
       else if(len == len / k * k) {
	       first = len / k;
	       len = first;
       }
       else {
       	first = len / k + 1;
        count = len - len / k * k;
       	len = len / k;
       }
       while(count) {
           res.push_back(list[id]);
           list[id+first-1]->next = NULL;
           id = id + first;
           --count;
           --k;
       }
       while(id < list.size()) {
       	--k;
        res.push_back(list[id]);
        list[id+len-1]->next = NULL;
       	id = id + len;
       }
       while(k>0) {
           --k;
       	res.push_back(NULL);
       }
       return res;
    }
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) 
    {
        vector<ListNode*> ans(k,NULL);
        ListNode * head = root;
        int length = 0;
        while(head)
        {
            head = head->next;
            length++;
        }
        vector<int>sizes(k,length/k);
        int mod = length % k;
        for(int i = 0; i < sizes.size() && root ; i++)
        {
            if(i < mod)
                sizes[i]++;
            ans[i] = root;
            for(int j = 0 ; j < sizes[i]  && root; j++)
            {
                ListNode * n = root->next;
                if(j + 1 == sizes[i])
                    root->next = NULL;
                root = n;
            }
        }
        return ans;
    }
};


