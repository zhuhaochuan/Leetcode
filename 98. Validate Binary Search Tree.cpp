/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：判断一颗二叉树是否是合法的BST
 * 中序遍历从小到大
 * 中序遍历的非递归和前序遍历的非递归基本一模一样
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        long long pre = LONG_MIN;//坑
        while(cur||!s.empty()) {
        	while(cur) {
        		s.push(cur);
        		cur = cur->left;
        	}
        	cur = s.top();
        	s.pop();
        	if(cur->val<=pre) return false;
        	pre = cur->val;
            cur = cur->right;
        }
        return true;
    }
};


//递归版本
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        TreeNode* pLast=NULL;
        return isValidBST(root, pLast);
    }
    bool isValidBST(TreeNode* p, TreeNode*& pLast)
    {
        if(p==NULL)
            return true;
        bool isValid=isValidBST(p->left, pLast);
        if(!isValid)
            return false;

        if(pLast==NULL)//对应中序遍历第一个元素，第一个元素没有比较对象
            pLast=p;
        else//对于其他元素 和前一个遍历到的元素进行比较
            if(p->val <=pLast->val)
                return false;
        pLast=p;
        return isValidBST(p->right, pLast);
    }
};







