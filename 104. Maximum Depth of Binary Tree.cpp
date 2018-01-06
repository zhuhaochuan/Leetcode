/**
 *分析：找到一颗二叉树的最大的深度
 *深度其实就是从根节点到叶子节点走过的最大的路径数
 *两种实现的方式 递归和迭代
 *都实现一下吧
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;//老问题 这里考虑到传入为空指针的情况 下面就不需要再特殊考虑
        int L ,R ,max_depth;
        L = maxDepth(root->left) + 1;
        R = maxDepth(root->right) + 1;
        max_depth = L > R ? L : R;
        return max_depth;
    }
};
