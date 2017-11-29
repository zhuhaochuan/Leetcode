/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//如果输入的数只有一个 那么直接输出这个数构成的根节点
//看需要怎样 的数据结构来构造
//显然需要遍历一遍这个数组
//所以时间复杂度至少O(N)
//感觉需要两个栈 
//
//62ms
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	TreeNode* root; TreeNode* pre; TreeNode* cur;
    	pre = new TreeNode(nums[0]);
    	root = pre;
    	for(int i=1;i<nums.size();i++) {
    	    cur = new TreeNode(nums[i]);
    		if(nums[i]<nums[i-1]) {
    			pre->right = cur;
    			pre = cur;
    		}
    		else if(nums[i]>nums[i-1]) {
    			if(nums[i]>root->val) {
    				cur->left = root;
    				root = cur;
    				pre = cur;
    			}
    			else if(nums[i]<root->val) {
    				TreeNode* p = root->right;
    				TreeNode* q = root;
    				while(nums[i]<p->val) {
    					q = p;
    					p = p->right;
    				}
    				q->right = cur;
    				cur->left = p;
    				pre = cur;
    			}
    		}
    	}

       return root;
    }
};

//53ms
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        deque<TreeNode*> dq;
        
        for (int i = 0; i < nums.size(); i++) {
            TreeNode* node = new TreeNode(nums[i]);
            while (!dq.empty() && dq.back()->val < node->val) {
                node->left = dq.back();
                dq.pop_back();
            }
            if (!dq.empty()) {
                dq.back()->right = node;
            }
            dq.push_back(node);
        }
        return dq.front();
    }
};