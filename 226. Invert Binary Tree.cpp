/**
 * 分析：翻转一颗二叉树
 * 就是做镜像对称
 * 想法就是 交换所有节点左右孩子
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(!root) return root;

    	TreeNode* temp = invertTree(root->right);
    	root->right = invertTree(root->left);
    	root->left = temp;
    	return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if(root->left)
            invertTree(root->left);
        if(root->right)
            invertTree(root->right);
        return root;
    }
};