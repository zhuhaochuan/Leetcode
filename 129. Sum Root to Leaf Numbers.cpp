/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：每个节点在0-9 每个根-叶子路径代表一个数 求所有路径数总和
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        helper(root,res,0);
        return res;
    }

    void helper(TreeNode* root,int& res,int num) {
    	if(!root->left&&!root->right) {
    		res += num*10+root->val;
    		return;
    	}
    	if(root->left) helper(root->left,res,num*10+root->val);
    	if(root->right) helper(root->right,res,num*10+root->val);
    	return;
    }
};