/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：将所有不包含1孩子的字数全部删除 本身也不包含1
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        bool tag = helper(root);
        if(tag&&root->val==0) return nullptr;
        else return root;
    }

    bool helper(TreeNode* node) {
    	if(!node) return true;
    	bool tag1 = helper(node->left);
    	bool tag2 = helper(node->right);
    	if(tag1) node->left = nullptr;
    	if(tag2) node->right = nullptr;
    	if(tag1&&tag2&&node->val==0)
    		return true;
    	else return false;
    }
};