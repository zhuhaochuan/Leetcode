/**得到二叉每层的结点数组
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        vector<int> vv;
        while(!q.empty()) {
          TreeNode* cur = q.front();
          q.pop();
          vv.push_back(cur->val);
          if(cur->left) q.push(cur->left);
          if(cur->right) q.push(cur->right);
          if(cur==last) {
            v.push_back(vv);
            vv.clear();//需要及时清空当前队列里已经被加入到结果里的值
            last = q.back();//更新每一层的最后一个结点 就是当前队列中最后一个结点
        }
    }
    return v;
 }
};