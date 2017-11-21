/**Populate each next pointer to point to its next right node. 
 *If there is no next right node, the next pointer should be set toNULL.
 *Initially, all next pointers are set toNULL.
 *
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


//队列层次遍历
//用一个变量tail去存储每层最后的结点 当当前处理的结点等于tail时tail更新。
void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        TreeLinkNode *tail=root;
        TreeLinkNode *temp;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            if(temp==tail) tail=q.back();
            else temp->next=q.front();
        }
    }


//方案 2 采用已知信息 在遍历的过程中去通过父亲结点的next信息给左右孩子结点以指示
class Solution {
public:
    void connect(TreeLinkNode *root) {
       if(!root) return;
       travel(root,NULL);
   }
   void travel(TreeLinkNode* p,TreeLinkNode* nextNode) {
   	if(!p) return;
   	if(nextNode) p->next = nextNode;
   	travel(p->left,p->right);
   	if(p->next) travel(p->right,p->next->left);//这里要做判断 以防越界
   	else travel(p->right,NULL);
   }
};



//不能用递归 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode *p = root, *q;
        while (p->left) {
            q = p;
            while (q) {
                q->left->next = q->right;
                if (q->next)
                    q->right->next = q->next->left;
                q = q->next;
            }
            p = p->left;
        }
    }
};