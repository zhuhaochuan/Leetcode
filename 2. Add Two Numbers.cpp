/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 分析：倒叙给出两个非负的整数 求出其和的倒叙数
 * 第一种方案就是提取两个数出来 求和再按照要求构造节点
 * 但是这样有点太傻了
 *
 * 同时遍历两个链表 如果都有值就相加赋予其中一个 如果产生10进位就向前传递这个进位
 *
 */
//思路完全没问题 主要就是几个判断的地方需要注意
//整个思路和实现还是挺清晰的就是。。。。为什么我整个流程的描述需要这么多行的代码
//别人的只需要。。。我一半的代码量。。。

//不过说句实话我的时间复杂度是o(max(m,n))
//空间复杂度为o(1) 因为是在原始链表上修改所以。。。。空间复杂度低啊！！！！
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* cur1 = l1; ListNode* cur2 = l2; ListNode* res = NULL;
    	int c = 0;
    	while(1) {//这个while循环找到出现有链表到头的前一个位置
    		int temp = cur1->val + cur2->val + c;
    		c = temp/10; int v = temp%10;
    		cur1->val = cur2->val = v;
    		if(!cur1->next||!cur2->next) break;
            cur1 = cur1->next; cur2 = cur2->next;
    	}
    	if(!cur1->next&&!cur2->next) {//如果两个链表一样长
    		if(c) {//判断是否是进位
    			ListNode* n = new ListNode(c);
    			cur1->next = n;
    			return l1;
    		}else return l1;
    	}
    	else {//链表不一样长
    		ListNode* cur = NULL;
    		if(cur1->next) res = l1; cur = cur1;
    		else res = l2; cur = cur2;//获取长链表的信息
    		cur = cur->next;
    		while(c&&cur) {//对于单个链表的处理
    			int temp = cur->val + c;
    			c = temp/10; int v = temp%10; cur->val = v;
    			if(cur->next) cur = cur->next;
    			else if(c&&!cur->next) {
    				ListNode* nn = new ListNode(c);
    				cur->next = nn; c = 0;
    			}
    		}
    	}
    	return res;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first;
        ListNode* start=new ListNode(0);
        first=start;
        int offset=0;
        while(l1 || l2 || offset)
        {//下面这句牛逼了。。。将几种情况统一起来的表示！！
            int value=(l1?l1->val:0) + (l2?l2->val:0) + offset;
            offset=value/10;//进位
            start->next=new ListNode(value%10);
            start=start->next;
            l1=l1?l1->next:l1;//如果链表不为空就前进否则不变
            l2=l2?l2->next:l2;
        }
        return first->next;
    }
};
//通过判断是否为空对于情况进行区分
//如果为空可以让其保持当前的状态 不影响其他的部分




