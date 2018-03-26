/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：给出一颗二叉树，判断这颗二叉树是否是镜像对称的
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        bool res = check(root->left,root->right);
        return res;
    }

    bool check(TreeNode* left,TreeNode* right) {
    	if(!right&&left||!left&&right) return false;
    	if(!right&&!left) return true;
    	if(right->val != left->val) return false;
    	bool tag1 = check(left->left,right->right);
    	bool tag2 = check(left->right,right->left);
    	return tag1&&tag2;
    }
};


class Solution {
public:
    bool isSame(TreeNode *root1, TreeNode *root2){
        if(!root1&&!root2)
            return true;
        else if(root1&&root2){
            if(root1->val!=root2->val)
                return false;
            return isSame(root1->left,root2->right)&&isSame(root1->right,root2->left);
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSame(root->left,root->right);
    }
};