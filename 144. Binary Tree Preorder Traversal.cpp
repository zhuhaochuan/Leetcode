/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };先序遍历二叉树
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* cur = root;

        while(!s.empty()||cur) {
        	if(!cur) {
        		cur = s.top();
        		s.pop();
        	}
        	res.push_back(cur->val);
        	if(cur->right)
        		s.push(cur->right);
        	cur = cur->left;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;

        if (root == nullptr)
            return ret;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* tp = st.top();
            st.pop();
            ret.push_back(tp->val);
            if (tp->right != nullptr) st.push(tp->right);
            if (tp->left != nullptr) st.push(tp->left);
        }

        return ret;
    }
};