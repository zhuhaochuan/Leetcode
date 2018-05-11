/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };找到结构相同的子树的根节点，只需要返回相同的多个子树根节点当中的任意一个。
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return vector<TreeNode*> ();
        vector<TreeNode*> res;
        unordered_map<string,int> table;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
        	TreeNode* cur = s.top();
        	s.pop();
        	helper(cur,res,table);
        	if(cur->left) s.push(cur->left);
        	if(cur->right) s.push(cur->right);
        }
        return res;
    }

    void helper(TreeNode* root,vector<TreeNode*>& res,unordered_map<string,int>& table) {
    	stack<TreeNode*> s;
        s.push(root);
        string tag = "";
        TreeNode* cur = root;
        //二叉树前序遍历非递归实现
        while(cur||!s.empty()) {
        	while(cur) {
        		s.push(cur);
        		tag += cur->val + '0';
        		cur = cur->left;
        	}
        	tag += '#';
        	cur = s.top();
        	s.pop();
        	cur = cur->right;
        }

        //cout << tag << endl;
        if(table[tag]==1) {
        	res.push_back(root);
            ++table[tag];
        }
        else ++table[tag];
    }
};

//采用递归的方式效率更高 可以一次性得到所有子节点的前序遍历序列
class Solution {
    unordered_map<string, bool> trees;
    vector<TreeNode*> result;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == nullptr) return result;
        string serial;
        visit(root, serial);
        return result;
    }

    void visit(TreeNode* root, string& serial)
    {
        if (root == nullptr){
            serial = "#";
            return;
        }
        serial = to_string(root->val);
        string str;
        visit(root->left, str);
        serial += str;
        visit(root->right, str);
        serial += str;
        auto it = trees.find(serial);

        if (it == trees.end())
        {
            trees[serial] = true;
        }
        else if (it->second22)
        {
            it->second = false;
            result.push_back(root);
        }
    }
};