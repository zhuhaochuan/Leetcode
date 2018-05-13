/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：前序遍历使得一颗二叉树构成一个链表的形式
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        vector<TreeNode*> v;
        while(cur||!s.empty()) {
        	while(cur) {
        		s.push(cur);
        		v.push_back(cur);
        		cur = cur->left;
        	}
        	cur = s.top();
        	s.pop();
        	cur = cur->right;
        }
        for(int i=0;i<v.size()-1;++i) {
        	v[i]->left = nullptr;
        	v[i]->right = v[i+1];
        }
        return;
    }
};

//按照题目要求，它要把左子树的所有节点按照前序的顺序，挂载在右子树的链表中，那么我们首先遇到的第一个问题，把左子树挂载在右边，那之前的跟节点的右子树怎么处理？
//只需要将之前根节点的右子树挂到左子树的前序遍历的最后一个元素的右边就可以了
//因为根节点的右子树本身就是左子树前序遍历最后一个元素之后遍历的元素
//左子树前序遍历的最后一个元素是根左孩子的最右的叶子节点
//如果根节点没有左孩子那么直接向右走继续判断
class Solution {
public:
    void flatten(TreeNode* node) {
        while (node) {
            if (node->left) {
                TreeNode *prev = node->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};

//java 的递归版本
public void flatten(TreeNode root) {

        if (root == null) return;
        if (root.left != null) {
            TreeNode cur = root.left;
            while (cur.right != null) {
                cur = cur.right;
            }
            cur.right = root.right;
            root.right = root.left;
            root.left = null;
        }
        flatten(root.right);
}



