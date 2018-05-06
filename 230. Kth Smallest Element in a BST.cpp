/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：找到第k个最小的元素在BST
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int res = 0;
        helper(root,k,res);
        return res;
    }

    void helper(TreeNode* node,int& k,int& res) {
    	if(!node) return;
    	if(k<1) return;
    	helper(node->left,k,res);
    	if(k==1) res = node->val;
    	--k;
    	helper(node->right,k,res);
    	return;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
		vector<int> nodes;
		func(nodes,root);
		return nodes[k-1];
    }
	void func(vector<int>& nodes, TreeNode* root)
	{
        if(root)
        {
            func(nodes,root->left);
		    nodes.push_back(root->val);
		    func(nodes,root->right);
        }

	}
};