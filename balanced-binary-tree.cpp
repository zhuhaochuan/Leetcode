/**
 *Given a binary tree, determine if it is height-balanced.
 *For this problem, a height-balanced binary tree is defined as a 
 *binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	if(!root) return true;
    	int tag = 1;//设置一个tag标志是否出现不平衡点
    	high(root,tag);//递归求结点的深度并同时判断是否平衡
    	return tag;
    }
    int high(TreeNode *p, int& tag) {
    	if(!p||tag==0) return 0;//tag = 0 直接判断 递归返回
    	int L = high(p->left,tag);
    	int R = high(p->right,tag);
    	if(L-R>1||R-L>1) tag = 0;//tag置0点
    	return L > R ? (L+1) : (R+1);
    }
};