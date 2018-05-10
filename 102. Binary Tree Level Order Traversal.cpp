/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };二叉树层序遍历
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>> ();
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = root,*tail = root;
        vector<vector<int>> res;
        vector<int> v;
        while(!q.empty()) {
        	cur = q.front();
        	v.push_back(cur->val);
        	q.pop();
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur == tail) {
        		res.push_back(v);
        		v.clear();
        		tail = q.back();
        	}
        }
        return res;
    }
};