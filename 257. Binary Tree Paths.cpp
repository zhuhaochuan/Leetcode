/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：给出一个二叉树，给出所有的根节点到叶子节点的路径
 * ["1->2->5", "1->3"]
 * 注意返回的要求是返回字符串
 * 我采用的是递归的方式进行添加 每次传递一个临时变量s保存当前的值
 * 直到出现叶子节点才添加到答案当中
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return vector<string> ();
        vector<string> res;
        append_path(root,res,string());
        return res;
    }

    void append_path(TreeNode* cur,vector<string>& res,string s) {
    	s += to_string(cur->val);//没有stoi。。只有itos 记住接口
    	if(cur->left) append_path(cur->left,res,s+"->");
    	if(cur->right) append_path(cur->right,res,s+"->");
    	if(!cur->left&&!cur->right) res.push_back(s);
    }
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> s;
        vector<string> ans;
        traverse(root, s, ans);
        return ans;
    }

    void traverse(TreeNode* node, vector<int>& s, vector<string>& ans) {
        if (!node) return;
        s.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            /* find a path from root->leaf */
            string temp = to_string(s[0]);
            for(int i = 1; i < s.size(); i++) {
                temp += "->";
                temp += to_string(s[i]);
            }
            ans.push_back(temp);
        } else {
            traverse(node->left, s, ans);
            traverse(node->right, s, ans);
        }
        s.pop_back();
    }
};