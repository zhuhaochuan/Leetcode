/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：不能连续抢劫直接相连的节点，求最大可抢到的价值
 * 自顶向下的话，对于当前节点 最大值为左右子树都不包含左右孩子节点的值加上当前节点的值与包含左右孩子（至少一个）的和的最大值
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int has_root = root->val,nhas_root = 0;
        vector<int> v = helper(root);
        return max(v[0],v[1]);
    }
    vector<int> helper(TreeNode* root) {
    	if(!root) return vector<int> {0,0};
    	vector<int> a = helper(root->left);
    	vector<int> b = helper(root->right);
    	int has = root->val + a[0] + b[0];//左右孩子都不包含 包含当前节点的值
    	int nhas = max(a[1],a[0]) + max(b[1],b[0]);//不包含当前节点的值，所以左右孩子可选可不选此时选取最大值
    	return vector<int> {nhas,has};
    }
};