/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };删除BST当中的指定节点 log(n)复杂度
 * 每次删除一个节点对于其左右子树有两种接法
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* cur = root,*newhead = new TreeNode(0),*pre = newhead;
        pre->right = root;
        while(cur) {
        	if(cur->val>key) {
        		pre = cur;
        		cur = cur->left;
        	}
        	else if(cur->val<key) {
        		pre = cur;
        		cur = cur->right;
        	}
        	else break;
        }
        if(!cur) return root;
        int tag = 0;
        if(pre->right==cur) tag = 1;
        TreeNode* l = cur->left,*r = cur->right;
        delete cur;
        if(!l&&!r) {
        	if(tag)
        		pre->right = nullptr;
        	else pre->left = nullptr;
        	return newhead->right;;
        }
        if(l) {
        	cur = l;
        	while(cur->right) {
        		cur = cur->right;
        	}
        	cur->right = r;
        	if(tag) pre->right = l;
        	else pre->left = l;
        }
        else if(!l&&r) {
        	cur = r;
        	while(cur->left)
        		cur = cur->left;
        	cur->left = l;
        	if(tag) pre->right = r;
        	else pre->left = r;
        }
        return newhead->right;
    }
};




class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            // key is not found, do nothing!!
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // get the right TreeNode
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr) {
                root = root->left;
            } else {
                // put left subtree to the left most of the right subtree
                TreeNode* temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                temp->left = root->left;

                // let right subtree be the new root
                temp = root;
                root = root->right;
                delete temp;
                temp = nullptr;
            }
        }
        return root;
    }
};