/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 给出一颗二叉搜索树 判断是否有两个元素的和等于目标值
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode*> s;
        vector<int> nums;
        TreeNode* cur = root;

        while(!s.empty()||cur) {
        	while(cur) {
        		s.push(cur);
        		cur = cur->left;
        	}
        	while(!cur&&!s.empty()) {
        		cur = s.top();
           		nums.push_back(cur->val);
           		s.pop();
           		cur = cur->right;
        	}
        }

        int n = nums.size();
        for(int i=0,j=n-1;i<j;) {
        	if(nums[i]+nums[j]<k)
        		++i;
        	else if(nums[i]+nums[j]>k)
        		--j;
        	else
        		return true;
        }
        return false;
    }
};


class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> v;
    inorder_travel(root, v);
    int i = 0, j = v.size() - 1;
    while(i < j) {
      int sum = v[i] + v[j];
      if(sum == k)
        return true;
      else if(sum < k)
        ++i;
      else
        --j;
    }
    return false;
  }

  void inorder_travel(TreeNode* root, vector<int>& v) {
    if(!root) return;
    inorder_travel(root->left, v);
    v.push_back(root->val);
    inorder_travel(root->right, v);
  }
};