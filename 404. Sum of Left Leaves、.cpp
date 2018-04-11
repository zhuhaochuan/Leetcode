/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：找到二叉树左叶子节点元素的和
 * 递归寻找每个叶子节点，使用一个tag标志是从父节点的哪边过来的
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int tag = 0,sum = 0;
        helper(root,tag,sum);
        return sum;
    }

    void helper(TreeNode* root,int& tag, int& sum) {
    	if(!root->left&&!root->right&&tag)
    		sum += root->val;
    	if(root->left) {
    		tag = 1;
    		helper(root->left,tag,sum);
    	}
    	if(root->right) {
    		tag = 0;
    		helper(root->right,tag,sum);
    	}
    }
};