/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：给出一个非负元素组成的二叉搜索树 找到任意两个元素当中绝对值差最小的值
 * 左子树的最大值，右子树的最小值
 * 中序遍历从小到大
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MAX,pre = -1;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty()||cur) {
        	while(cur) {
        		s.push(cur);
        		cur = cur->left;
        	}
        	cur = s.top();
        	int temp = pre>=0?cur->val-pre:INT_MAX;
        	res = min(res,temp);
        	s.pop();
        	pre = cur->val;
        	cur = cur->right;
        }
        return res;
    }
};


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left != NULL) getMinimumDifference(root->left);
		if (val >= 0) min_dif = min(min_dif, root->val - val);
		val = root->val;
		if (root->right != NULL) getMinimumDifference(root->right);
		return min_dif;
	}
private:
	int min_dif = INT_MAX, val = -1;

};