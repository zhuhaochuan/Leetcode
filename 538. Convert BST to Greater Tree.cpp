/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：将一个BST转化成一个更大的树
 * 每一个节点的值需要加上其他所有比该节点大的元素的值得和
 * 因为是BST所以比当前节点大的元素都在其右子树
 * 采用类似前序遍历的方式不过是先遍历右子树在遍历自己再遍历左子树
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        help(root,sum);
        return root;
    }

    void help(TreeNode* root,int& sum) {
    	if(!root) return;
    	help(root->right,sum);
        sum += root->val;
        root->val = sum;
    	help(root->left,sum);
    	return;
    }
};


class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        convertBST(root->right);
        root->val = (sum += root->val);
        convertBST(root->left);
        return root;
    }
};