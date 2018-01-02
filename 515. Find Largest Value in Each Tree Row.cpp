/**
 * 分析：输出二叉树每一行最大的值
 *简单的思路就是 层序遍历每一层
 *使用一个变量去保存每一层最大的值 在遍历的过程当中去修改这个最大值
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        int max = INT_MIN;//这里使用整数的最小值 会根据系统的位数变化
        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	q.pop();
        	if(cur->val>max) max = cur->val;
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur == last) {
        		last = q.back();
        		res.push_back(max);
        		max = INT_MIN;
        	}
        }
        return res;
    }
};


//其他的解法
class Solution {
public:
    void helper(vector<int> &res, TreeNode *root, int level){
        if(root == NULL)
            return;
        if(level >= res.size())
            res.resize(level + 1, INT_MIN);
        if(res[level] < root->val)
            res[level] = root->val;
        helper(res, root->left, level + 1);
        helper(res, root->right, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(res, root, 0);
        return res;
    }
};



class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        list<TreeNode*> current;

        if (root != nullptr) {
            current.push_back(root);
        }

        while (current.size()) {
            int max_value = INT_MIN;
            int size = current.size();
            while (size) {
                TreeNode* node = current.front();
                max_value = max(max_value, node->val);
                current.pop_front();
                if (node->left != nullptr) {
                    current.push_back(node->left);
                }

                if (node->right != nullptr) {
                    current.push_back(node->right);
                }
                size--;
            }
            result.push_back(max_value);
        }

        return result;
    }
};