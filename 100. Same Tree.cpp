/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 判断两颗二叉树是否一样
 */
//递归实现
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p&&q||!q&&p) return false;
        if(p->val==q->val) {
        	bool l = isSameTree(p->left,q->left);
        	bool r = isSameTree(p->right,q->right);
        	return l&&r;
        }
        else return false;
    }
};

//简练写法
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
	    if (p == NULL || q == NULL) return (p == q);
	    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
};

//双重队列法 使用循环实现
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL || q == NULL) return false;
        queue<TreeNode *> ptree, qtree;
        ptree.push(p);
        qtree.push(q);
        while (!ptree.empty() && !qtree.empty())
        {
            TreeNode *pcur = ptree.front(), *qcur = qtree.front();
            int vp = pcur->val, vq = qcur->val;
            ptree.pop();
            qtree.pop();
            if (vp != vq) return false;
            if (pcur->left != NULL && qcur->left != NULL)
            {
                ptree.push(pcur->left);
                qtree.push(qcur->left);
            }
            else if (pcur->left == NULL && qcur->left == NULL);
            else return false;

            if (pcur->right != NULL && qcur->right != NULL)
            {
                ptree.push(pcur->right);
                qtree.push(qcur->right);
            }
            else if (pcur->right == NULL && qcur->right == NULL);
            else return false;

        }
        return true;
    }
};