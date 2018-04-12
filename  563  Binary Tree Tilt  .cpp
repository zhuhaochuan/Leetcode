/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };对于每一个节点定义一个值为其左子树元素的和减去右子树元素的和的绝对值
 * 叶子节点的相应值为0，求解整棵树该值得和
 *
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        helper(root,sum);
        return sum;
    }

    int helper(TreeNode* root,int& sum) {
    	if(!root)
    		return 0;
    	int l = helper(root->left,sum);
    	int r = helper(root->right,sum);
    	sum += abs(l-r);
    	return l + r + root->val;
    }
};