/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };等价于层序遍历得到每层最后一个元素值
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int> ();
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur = root,*tail = root;
        vector<int> res;
        while(!q.empty()) {
        	cur = q.front();
        	q.pop();
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur == tail) {
        		res.push_back(cur->val);
        		tail = q.back();
        	}
        }
        return res;

    }
};