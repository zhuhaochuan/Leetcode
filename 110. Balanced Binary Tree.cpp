/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 判断一颗二叉树是不是平衡二叉树
 * 采用递归的方式
 * 递归求得每个节点的深度，使用一个tag变量标志是否平衡 如果出现不平衡直接返回
 * 深度：对于任意节点n,n的深度为从根到n的唯一路径长，根的深度为0；
   高度：对于任意节点n,n的高度为从n到一片树叶的最长路径长，所有树叶的高度为0；
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int tag = 1;
        check(root,tag);
        return tag;
    }

    int check(TreeNode* cur,int& tag) {
    	if(!cur) return 0;
    	int l = check(cur->left,tag) + 1;
    	int r = check(cur->right,tag) + 1;
    	if(l-r>1||r-l>1) {
    		tag = 0;
    		return 0;
    	}
    	return max(l,r);
    }
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left==-1||right==-1||abs(left-right)>1) return false;
        else return true;
    }
    int depth(TreeNode* cur)
    {
        if(!cur) return 0;
        int left = depth(cur->left);
        int right = depth(cur->right);
        if(left==-1||right==-1||abs(left-right)>1) return -1;
        else return max(left,right)+1;
    }
};
