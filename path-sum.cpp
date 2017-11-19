/**
 *题目：给定一个sum值 判断给定的二叉树是否有路径可以正好满足这个sum
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
    bool hasPathSum(TreeNode *root, int sum) {
      if(!root) return false;
      int tag = 0;
      travel(root,sum, tag, 0);
      return tag;
    }
    void travel(TreeNode* p, int sum, int &tag, int cur) {
      if(!p||tag==1) return;
      cur += p->val;
      if(!p->left&&!p->right&&cur==sum) tag = 1; return;
      travel(p->left,sum,tag,cur);
      travel(p->right,sum,tag,cur);
    }
};


//怎样将代码显示的更加简洁并且少用中间变量和参数
//递归求解，当root为空返回false，当到达叶子节点，并且和位sum返回true
//其他情况递归调用左右子树
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
       if(root == NULL)
           return false;
        if(root->left == NULL && root->right == NULL && sum - root->val == 0)
           return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};