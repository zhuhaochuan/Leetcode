/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：找到一颗二叉树当中的最长路径
 * 这条路径可以绕过根节点
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        helper(root,sum);
        return sum;
    }
    int helper(TreeNode* root,int& sum) {
        if(!root) return 0;
        int l = helper(root->left,sum) + 1;
        int r = helper(root->right,sum) + 1;
        sum = (l - 1 + r - 1) > sum ? (l - 1 + r - 1) : sum;
        return max(l,r);
    }
};