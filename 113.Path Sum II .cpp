/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：找到所有的根节点到叶子节点的和为目标值得所有路径
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>> ();
        vector<vector<int>> res;
        dfs(root,res,sum,vector<int>());
        return res;
    }

    void dfs(TreeNode* root,vector<vector<int>>& res,int sum,vector<int> temp) {
    	temp.push_back(root->val);
    	if(!root->left&&!root->right&&sum-root->val==0) {
    		res.push_back(temp);
    	}
    	if(root->left)
    		dfs(root->left,res,sum-root->val,temp);
    	if(root->right)
    		dfs(root->right,res,sum-root->val,temp);
    	return;
    }
};



class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return vector<vector<int>> ();
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root,res,sum,temp);//形参是引用 所以这里
        return res;
    }

    void dfs(TreeNode* root,vector<vector<int>>& res,int sum,vector<int>& temp) {//传递的是temp的引用所以传入的实参不能是个临时变量
    	temp.push_back(root->val);
    	if(!root->left&&!root->right&&sum-root->val==0) {
    		res.push_back(temp);//虽然使用的都是一个temp但是实际放进容器内的是temp的深拷贝 并不是temp本身 如果都是temp那就完蛋了
            return;
    	}
    	if(root->left)
        {
            dfs(root->left,res,sum-root->val,temp);
            temp.pop_back();//传递的是引用 所以得到一个结果返回的时候需要还原现场
        }
    	if(root->right) {
    		dfs(root->right,res,sum-root->val,temp);
            temp.pop_back();//传递的是引用 所以得到一个结果返回的时候需要还原现场
        }
    	return;
    }
};