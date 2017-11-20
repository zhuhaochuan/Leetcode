/*Given a binary tree, find the maximum path sum.
 *The path may start and end at any node in the tree.
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
    int maxPathSum(TreeNode *root) {
    	if(!root) return 0;
    	int maxSum = -65535;//这里的初始值必须设为一个不可能达到的负数 最大值有可能为负的情况
    	maxlu(root,maxSum);//递归遍历所有结点的同时时刻更新可能的最大路径值
    	return maxSum;
    }
    int maxlu(TreeNode* root, int& maxSum) {
    	if(!root) return 0;
    	int L = maxlu(root->left,maxSum);
    	int R = maxlu(root->right,maxSum);
    	if(root->val>maxSum) maxSum = root->val;
    	if((L+R+root->val)>maxSum) maxSum = L+R+root->val;
    	int curVal =  L > R ? L + root->val : R + root->val;
    	if(curVal>maxSum) maxSum = curVal;
    	if(curVal > 0) return curVal; //只有大于0的分支路径是需要的否则只会降低当前最大值 
    	else return 0;
    }
};