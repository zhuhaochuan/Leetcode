/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：找到一棵二叉搜索树的两个节点的最低公共祖先 节点自己可以是自己的祖先
 * 3、普通二叉树
先找出从跟节点分别到两个节点的路径。（方法：二叉树后序遍历的非递归，将遍历的节点保存在list中。） 
两个list同时往前走，找出最后一个相等的节点，就是最近公共祖先节点
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val>=p->val&&root->val<=q->val||root->val>=q->val&&root->val<=p->val)
        	return root;
        else if(root->val>=max(q->val,p->val))
        	return lowestCommonAncestor(root->left,p,q);
        else
        	return lowestCommonAncestor(root->right,p,q);
    }
};