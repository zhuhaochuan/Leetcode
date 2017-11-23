/**非递归版本的中序遍历
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> v;
    	if(!root) return v;
    	stack<TreeNode*> s;
    	TreeNode* cur = root;
    	do{
    		while(cur) {
    			s.push(cur);
    			cur = cur->left;
    		}
    		if(!s.empty()) {
    			cur = s.top();
    			v.push_back(cur->val);
    			s.pop();
    			cur = cur->right;
    		}
    	} while(cur||!s.empty());

    	return v;
    }
};