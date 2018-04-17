/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：递归的寻找判断每个节点是不是子树的根节点找到就跳出否则继续寻找
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s&&!t) return true;
        if(!s||!t) return false;
        return helper(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool helper(TreeNode* s, TreeNode* t) {
    	if(!s&&!t) return true;
    	else if(!s||!t) return false;
    	if(s->val!=t->val) return false;
    	return helper(s->left,t->left)&&helper(s->right,t->right);
    }
};


class Solution {
public:
    bool isSametree(TreeNode* s, TreeNode* t) {
	if (!s && !t) return true;//如果都为空，true。
	if (!s || !t) return false;//如果一个为空，一个不为空，false。
	if (s->val != t->val) return false;//如果节点上面的值不同，false。
	return isSametree(s->left, t->left) && isSametree(s->right, t->right);
}
    bool isSubtree(TreeNode* s, TreeNode* t) {
     if (s==NULL||t==NULL)//其中一个为空：两颗二叉树肯定不相同。两者都为空：寻找到最后都没有找到相同的，同样返回false
    {
		return false;
    }
	if (isSametree(s,t))
	{
		return true;
	}
	return isSubtree(s->left,t)||isSubtree(s->right,t);
}

};