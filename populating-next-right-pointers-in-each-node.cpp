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
//方案1 采用队列保存结点的方式 这样的空间复杂度为不是常数级别的 超过限制内存
class Solution {
public:
    void connect(TreeLinkNode *root) {
       if(!root) return;
       queue<TreeLinkNode*> q;
       if(root->left) q.push(root->left);
       if(root->right) q.push(root->right);
       while(!q.empty()) {
       	TreeLinkNode* cur = q.front();
       	q.pop();
       	if(!q.empty()||(q.size()%2 == 1)) cur->next = q.front();
       	if(cur->left) q.push(root->left);
        if(cur->right) q.push(root->right);
       }
   }
};

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