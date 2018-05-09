/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };分析：深拷贝一个带有随机指针的链表
 */
//时间复杂度o(n) 空间复杂度o(n)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        map<RandomListNode*,RandomListNode*> table;
        RandomListNode* cur = head,*pre = new RandomListNode(0);
        while(cur) {
        	table[cur] = new RandomListNode(cur->label);
        	pre->next = table[cur];
            pre = table[cur];
        	cur = cur->next;
        }
        pre->next = nullptr;
        cur = head;
        while(cur) {
        	table[cur]->random = cur->random?table[cur->random]:nullptr;
            cur = cur->next;
        }
        return table[head];
    }
};

/*
那么有没有办法可以不用额外空间来完成这个任务呢？还是有的，前面我们需要一个哈希表的原因是当我们访问一个结点时可能它的随机指针指向的结点还没有访问过，
结点还没有创建，所以我们需要线性的额外空间。想避免使用额外空间，我们只能通过利用链表原来的数据结构来存储结点。基本思路是这样的，对链表进行三次扫描，
第一次扫描对每个结点进行复制，然后把复制出来的新节点接在原结点的next，也就是让链表变成一个重复链表，就是新旧更替；
第二次扫描中我们把旧结点的随机指针赋给新节点的随机指针，因为新结点都跟在旧结点的下一个，所以赋值比较简单，就是node.next.random = node.random.next，
其中node.next就是新结点，因为第一次扫描我们就是把新结点接在旧结点后面。现在我们把结点的随机指针都接好了，
最后一次扫描我们把链表拆成两个，第一个还原原链表，而第二个就是我们要求的复制链表。因为现在链表是旧新更替，只要把每隔两个结点分别相连，
对链表进行分割即可。这个方法总共进行三次线性扫描，所以时间复杂度是O(n)。而这里并不需要额外空间，所以空间复杂度是O(1)。比起上面的方法，
这里多做一次线性扫描，但是不需要额外空间，还是比较值的。
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *newHead, *l1, *l2;
        l1 = head;
        while(l1) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l1->next->next;
        }

        l1 = head;
        while(l1) {
            if(l1->random)
                l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }

        l1 = head;
        newHead = l1->next;
        while(l1) {
            l2 = l1->next;
            l1->next = l2->next; // Must restore the original list
            if(l2->next) l2->next = l2->next->next;
            l1 = l1->next;
        }

        return newHead;
    }
};