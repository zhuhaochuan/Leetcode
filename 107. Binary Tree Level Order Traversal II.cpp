/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };给出一个二叉树，从低到高按层输出每一层节点
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tail = root;
        vector<vector<int>> res;
        vector<int> temp;
        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	temp.push_back(cur->val);
        	q.pop();
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur==tail) {
        		tail = q.back();
        		res.insert(res.begin(),temp);//在指定位置之前插入元素
        		temp = vector<int>();
        	}
        }
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) { //层次遍历  通过队列  依次访问队列里节点， 再将左右孩子入列
        vector<vector<int>> res;
        vector<int> l;
        queue<TreeNode *> q;
        TreeNode *p;
        int i,size;
        if (root){
            q.push(root);
        }
        while(!q.empty()){
            l.clear(); //clear
            size = q.size();
            for (i=0;i<size;i++){
                p = q.front(); // 队首
                q.pop(); // 出队
                l.push_back(p->val);
                if (p->left){
                    q.push(p->left);
                }
                if (p->right){
                    q.push(p->right);
                }
            }
            res.push_back(l); // vector
        }
        reverse(res.begin(),res.end());  // 方法 逆转
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> a;
        helper(root, a, 0);
        reverse(a.begin(),a.end());
        return a;
    }
    void helper(TreeNode* root, vector<vector<int>> &a, int n){
        if(!root) return;
        if(a.size() < n + 1)
            a.push_back({});
        a[n].push_back(root->val);
        helper(root->left, a, n + 1);
        helper(root->right, a, n + 1);
    }
};