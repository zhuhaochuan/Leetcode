/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };分析：给出一个完全二叉树，给每个节点的next指针连接向其右边的节点，如果没有右边的节点那么就指向nullptr
 * 附加条件是不能使用额外空间 所以不可以使用自定义的栈空间 可以使用调用栈进行存储
 *
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        root->next = nullptr;
        dfs(root);
        return;
    }
    void dfs(TreeLinkNode *root) {
        if(!root) return;
        if(root->left)  root->left->next = root->right;
        if(root->right) root->right->next = root->next?root->next->left:nullptr;
        dfs(root->left);
        dfs(root->right);
        return;
    }
};



class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
        return;

	    while(root -> left)
	    {
	        TreeLinkNode *p = root;
	        while(p)
	        {
	            p -> left -> next = p -> right;
	            if(p -> next)
	                p -> right -> next = p -> next -> left;
	            p = p -> next;//对同层的每一个节点进行处理
	        }
	        root = root -> left;//下一层第一个节点
	    }
    }
};



