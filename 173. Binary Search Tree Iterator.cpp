/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 *
 */
class BSTIterator {
private:
	stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        while(root) {
        	s.push(root);
        	root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number
    返回当前最小值
     */
    int next() {
    	TreeNode* cur = s.top();
    	s.pop();
    	TreeNode* right = cur->right;
    	while(right) {
    		s.push(right);
    		right = right->left;
    	}
    	return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */