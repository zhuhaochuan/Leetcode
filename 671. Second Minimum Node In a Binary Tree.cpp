/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：给定一颗二叉树每个节点要么有两个孩子要么就没有孩子
 * 每个节点必然是其左右孩子当中最小的那个节点的值
 * 求解这棵树当中第2小的元素只，若没有则返回-1
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        if(!root->left&&!root->right) return -1;
        int res = 0;
        int l = helper(root->left,root->val);
        int r = helper(root->right,root->val);
        if(l == r && root->val == l) return -1;
        else {
            if(min(l,r)>root->val)
                return min(l,r);
            else return max(l,r);
        }
    }

    int helper(TreeNode* root,int val) {
        if(!root) return val;
    	if(root->val>val) return root->val;
    	int l = helper(root->left,val);
    	int r = helper(root->right,val);
    	return min(l,r)>val?min(l,r):max(l,r);
    }
};


class Solution {
public:
    int helper(TreeNode* root, int first)
    {
        if(!root)
        {
            return -1;
        }

        if(root->val > first)
        {
            return root->val;
        }

        int left = helper(root->left, first);
        int right = helper(root->right, first);
        if(left == -1)
            return right;
        if(right == -1)
            return left;

        return min(left,right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        return helper(root, root->val);
    }
};