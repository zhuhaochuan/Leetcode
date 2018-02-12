/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *将k个有序的链表合并成一个新的有序链表 分析且降低复杂度
 *1 2 3 ，2 4 5，4 5 7 8；
 *第一种想法就是采用之前的两个有序链表的合并方式采用分而治之的方式
 *两两合并再最终合并 复杂度应该是log(k)(m+n)    (m+n)为每一对假设的节点长度
 *参数是两个指针 返回合并的链表
 *如果这两个指针的值相差的不是1就再度分解
 *0 1 2
 *0 1 2 3 4 5
 *
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(!len) return NULL;
        if(len==1)return lists[0];
        if(len%2) {
        	ListNode* temp = devide(0,len-2,lists);
        	return merge(lists[len-1],temp);
        }
        else return devide(0,len-1,lists);
    }
//分而治之
    ListNode* devide(int l,int r,vector<ListNode*>& lists) {
    	if(l+1==r) return merge(lists[l],lists[r]);
    	if((r-l+1)%2) {
    		ListNode* temp = devide(l,r-1,lists);
    		return merge(temp,lists[r]);
    	}
    	else {
    		ListNode* first = devide(l,l+(r-l)/2,lists);//注意计算出偏移之后需要加上初试值l才是中间值
    		ListNode* second = devide(l+(r-l)/2+1,r,lists);
    		return merge(first,second);
    	}
    }
//合并两个有序链表
    ListNode* merge(ListNode* first,ListNode* second) {
        if(!first) return second;
        if(!second) return first;
    	if(first->val>second->val) return merge(second,first);
    	ListNode* l = first,* r = first->next,* cur = second;
        if(!r) {
            l->next = second;
            return first;
        }
    	while(cur) {
    		while(r&&cur->val>r->val) {
    			l = r;
    			r = r->next;
    		}
    		if(!r) {
    			l->next = cur;
    			return first;
    		}
    		l->next = cur;
    		ListNode* temp = cur->next;
    		l = cur;
    		cur->next = r;
    		cur = temp;
    	}
    	return first;
    }
};


//另一种合适的方法是采用优先级队列 也就是堆的方式进行处理
//将所有非空的头结点存储到优先级队列当中 队列的优先级最大的也就是最小的那个节点的值
//每次pop出最小的节点 同时该节点后移一位入队列 队列自动调整保证下次pop出的必然还是最小节点
//直到队列为空 说明已经构造完毕


class Solution {
public:
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *pre = NULL;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto list : lists) {
            if (list)
                pq.emplace(list);
        }
        if(!pq.size()) return head;
        //如果队列当中没有元素也就是为空 再进行top()得到的是一个空指针的引用
        //就会报错 队列的pop只是单一的执行删除的工作 并不返回该元素的引用。
        head = pq.top(); pre = head; pq.pop();
        if(head->next) pq.push(head->next);
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (cur->next) {
                pq.emplace(cur->next);
            }
            pre->next = cur;
            pre = cur;
        }
        return head;
    }
};



