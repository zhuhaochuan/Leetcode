/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：求解一颗二叉树是否存在路径使得根节点到叶子节点之间的值之和为目标值
 * 最简单方式就是递归实现
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return find_path(root,sum);
    }
    bool find_path(TreeNode* cur,int sum) {
    	if(!cur->left&&!cur->right&&sum-cur->val==0) return true;
    	if(cur->left&&find_path(cur->left,sum-cur->val)) return true;//对于空节点的判断其实是多余的，因为到了叶子节点就不会再往下走
    	if(cur->right&&find_path(cur->right,sum-cur->val)) return true;
    	return false;
    }
};

//人家的简便代码值得学习
class Solution
{
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (!root)
            return false;
        return helper(root, sum);
    }
    bool helper(TreeNode* root, int sum)
    {
        if (!root->left && !root->right)
            return (sum == root->val);
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};