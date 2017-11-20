/**Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int>> v;
        vector<int> curv;
    	if(!root) return v;
    	travel(root,sum,v,curv);
    	return v;
    }
    void travel(TreeNode* p, int sum, vector<vector<int>>& v,vector<int> curv) {
    	if(!p) return;
    	curv.push_back(p->val);
    	int cur = sum - p->val;
    	if(!p->left&&!p->right&&cur==0) v.push_back(curv);
    	travel(p->left,cur,v,curv);
    	travel(p->right,cur,v,curv);
    }
};