/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：给出一个BST求出所有出现频次最高的元素
 */

//每一个节点右子树的元素大于等于这个节点的值
//左子树的元素的值小于等于这个元素的值
//不代表当前元素只有左右孩子才能和当前元素相等 可以在后面出现。。、
//
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return vector<int> ();
        int pre = root->val,max = 1;
        vector<int> res{root->val};
        map<int,int> table;
        table[root->val] = 1;
        helper(root->left,pre,res,table,max);
        helper(root->right,pre,res,table,max);
        return res;
    }

    void helper(TreeNode* root,int pre,vector<int>& res,map<int,int>& table,int& max) {
    	if(!root) return;
    	if(root->val==pre) {
    		++table[root->val];
    		if(table[root->val]>max) {
    			max = table[root->val];
    			res = vector<int>{root->val};
    		}
    		else if(table[root->val]==max) {
    			res.push_back(root->val);
            }
    		helper(root->left,pre,res,table,max);
    		helper(root->right,pre,res,table,max);
    	}
    	else {
    		++table[root->val];
            if(table[root->val]==max) {
    			res.push_back(root->val);
            }
    		helper(root->left,root->val,res,table,max);
    		helper(root->right,root->val,res,table,max);
    	}
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return vector<int> ();
        int max = 1;
        vector<int> res{root->val};
        map<int,int> table;
        table[root->val] = 1;
        helper(root->left,res,table,max);
        helper(root->right,res,table,max);
        return res;
    }

    void helper(TreeNode* root,vector<int>& res,map<int,int>& table,int& max) {
    	if(!root) return;
		++table[root->val];
		if(table[root->val]>max) {
			max = table[root->val];
			res = vector<int>{root->val};
		}
		else if(table[root->val]==max) {
			res.push_back(root->val);
        }
        helper(root->left,res,table,max);
        helper(root->right,res,table,max);
    }

};


// 题目中的follow up说了让我们不用除了递归中的隐含栈之外的额外空间，那么我们就不能用哈希表了，不过这也不难，
// 由于是二分搜索树，那么我们中序遍历出来的结果就是有序的，这样我们只要比较前后两个元素是否相等，就等统计出现某个元素出现的次数，
// 因为相同的元素肯定是都在一起的。我们需要一个结点变量pre来记录上一个遍历到的结点，然后mx还是记录最大的次数，cnt来计数当前元素出现的个数，
// 我们在中序遍历的时候，如果pre不为空，说明当前不是第一个结点，我们和之前一个结点值比较，如果相等，cnt自增1，如果不等，cnt重置1。
// 如果此时cnt大于了mx，那么我们清空结果res，并把当前结点值加入结果res，如果cnt等于mx，那我们直接将当前结点值加入结果res，然后mx赋值为cnt。最后我们要把pre更新为当前结点
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        TreeNode* pre= NULL;
        int gmax = INT_MIN;
        int cnt=0;
        helper(root,res,pre,cnt, gmax);
        return res;
    }
    void helper(TreeNode* root,vector<int>& res, TreeNode*& pre,int& cnt,int& gmax){
        if(!root) return ;
        helper(root->left,res,pre,cnt,gmax);
        if(pre!= NULL){
            cnt = pre->val == root->val ?  cnt+1: 1;
        }else
            cnt++;
        if(cnt >= gmax ){
            if(cnt > gmax) res.clear();//清空一个数组
            res.push_back(root->val);
            gmax = cnt;
        }
        pre = root;
        helper(root->right,res,pre,cnt,gmax);
    }
};