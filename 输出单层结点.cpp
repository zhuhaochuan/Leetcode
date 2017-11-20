/*对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，
请返回一个链表ListNode，代表该深度上所有结点的值，请按树上从左往右的顺序链接，
保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/


class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        vector<int> v;
        deep(root,dep,v);
        int size = v.size();
        if(size == 0) return NULL;
        ListNode* pre,*cur,*ans; //指针的声明 需要都写清楚是指针

        pre = new ListNode(v[0]);
        cur = pre; ans = pre;
        for(int i = 1;i<size;i++){
            cur = new ListNode(v[i]);
            pre->next = cur;
            pre = cur;
        }
        return ans;
    }

    void deep(TreeNode* p, int dep, vector<int> cur) {
        if(i<1||!p) return;
        if(i==1&&p) v.push_back(p->val);
        if(i>1&&p) {
            deep(p->left,dep-1,cur);
            deep(p->right,dep-1,cur);
        }
    }

};
//深度 ！！尼玛  根节点深度为1；深度等于层数
////版本1 思路其实很简单 因为需要寻找到对应深度的层的结点并且从左往右输出
//递归的想法比较直接 就直接前序遍历这棵树
//将要找到的深度即层数当做参数传入 
//对于当前结点找深度为dep的层其实也就是对其左右孩子找深度为dep-1 的层
//每次递归dep-1 直到 dep==1时 且当前处理的结点不为空
//就是找到了 将其push进vector
//最后再将数组中的元素连接成链表。


//版本2  不用再用个数组去存储 减少空间开销
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        ListNode* ans,*cur;
        ans = new ListNode(-1); 
        cur = ans;
        deep(root,dep,cur);
        
        return ans->next;
    }

    void deep(TreeNode* p, int dep, ListNode*& cur) {
        if(dep<1||!p) return;
        if(dep==1&&p) {
            cur->next = new ListNode(p->val);
            cur = cur->next;
        }
        if(dep>1&&p) {
            deep(p->left,dep-1,cur);
            deep(p->right,dep-1,cur);
        }
    }

};

//没问题！
//就是返回的时候需要返回 设立的头结点的下一个结点
//如果不设置头结点在递归中逐渐添加结点的时候
//会比较麻烦 需要保存上一个结点的指针 然后再和当前新建的结点连接起来。
