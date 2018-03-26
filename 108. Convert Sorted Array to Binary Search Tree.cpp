/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 给出一个升序排序的数组，构造一个二叉搜索树
 *采用递归的方式进行构造，构造出来的结果不唯一
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
        TreeNode* root = build(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* build(vector<int>& nums,int begin, int end) {
    	if(begin>end) return NULL;
    	int mid = begin + (end - begin)/2;
    	TreeNode* cur = new TreeNode(nums[mid]);
    	cur->left = build(nums,begin,mid-1);
    	cur->right = build(nums,mid+1,end);
    	return cur;
    }
};