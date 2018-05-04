/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：在每个深度d-1的非空节点增加两个值为v的孩子节点原始的左右子树分别加到原始左右位置
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return nullptr;
        if(d==1) {
        	TreeNode* newnode = new TreeNode(v);
        	newnode->left = root;
        	return newnode;
        }
        helper(root,v,d,1);
        return root;
    }

    void helper(TreeNode* node,int v,int d,int cur_d) {
    	if(!node) return;
    	if(cur_d==d-1) {
    		TreeNode* l = node->left;
    		TreeNode* r = node->right;
    		node->left = new TreeNode(v);
    		node->right = new TreeNode(v);
    		node->left->left = l;
    		node->right->right = r;
    		return;
    	}
    	else {
    		helper(node->left,v,d,cur_d+1);
    		helper(node->right,v,d,cur_d+1);
    	}
    	return;
    }
};



class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 0 || d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            (d ? newRoot->left : newRoot->right) = root;
            return newRoot;
        }
        if (root && d > 1) {
            root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
};