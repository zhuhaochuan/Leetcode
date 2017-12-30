/**
 * 分析：输出每一层的节点值得平均值 浮点数输出
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        vector<double> temp;
        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	q.pop();
        	temp.push_back(cur->val);
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur==last) {
        		double sum = 0;
        		for(auto each : temp)
        			sum += each;
        		res.push_back(sum/temp.size());
        		temp.clear();
        		last = q.back();
        	}
        }
        return res;
    }
};

//同样的思路 写法稍微有点差异
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> rets;
        if( !root)
            return rets;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double curr = 0;
            for( int i = 0; i < size; i++){
                TreeNode* next = q.front();
                q.pop();
                curr+=next->val;
                if( next->left) q.push(next->left);
                if( next->right ) q.push(next->right);
            }
            rets.push_back( curr/size);
        }
        return rets;
    }
};