/*
请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。
保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        if(!root) return -1;
        int tag = 0, ans = -1;
        sec(root,tag,p,ans);
        return ans;   
    }

    void sec(TreeNode* q,int& tag,int &p,int& ans){
        if(!q) return ;
        sec(q->left,tag,p,ans);
        if(tag==1){
            ans = q->val;
            tag = 0;
        }
        if(q->val==p) tag = 1;
        sec(q->right,tag,p,ans);
    }
};
//版本1  利用中序遍历递归方法实现 
//用参数tag标志是否已经找到指定结点
//如果tag为1 那么当前结点就是需要找的后继结点。

class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        if(!root) return -1;
        int tag = 0;
        return sec(root,tag,p); 
    }

    int sec(TreeNode* q,int& tag,int &p){
        if(!q) return -1;
        int left = sec(q->left,tag,p);
        if(left!=-1) return left;
        else 
            if(tag==1){
            tag = 0;
            return q->val;
        }
        if(q->val==p) tag = 1;
        return  sec(q->right,tag,p);
    }
};
//版本2  只需要一个额外的参数 tag
//当tag为1的时候当前结点就是需要找的后继结点直接返回
//当递归返回的值不是-1的时候就连续返回 不需要再找了