/**
 * 分析：题目意思就是找到最后一行的最左边的节点的值
 *这不就是层序遍历然后输出最后一层的第一个节点的值么？
 *只要解决如和分层 什么时候这是最后一层的问题
 *
 * 怎么区分二叉树的每一层 之前遇到的输出二叉树的每一层的节点的题目遇到过这样的问题
 *采用一个last来制定当前层的最后一个节点cur=last的时候 更新last 让其指向队列最后一个元素
 *在这里需要做一些变形 肯定是要遍历一遍这颗树的但是 我们不需要输出中间层的节点
 *我们只需要得到最后一层的节点组成的数组 然后输出这个数组的第一个数就可以了
 *
 *
 *
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        vector<int> temp;

        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	temp.push_back(cur->val);
        	q.pop();
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur==last) {
        		last = q.back();
        		if(q.empty())
        			return temp[0];
        		else temp.clear();
        	}
        }
    }
};


//另一种实现的方法
//在队列里每一层的最后添加标识
//当处理到标识的时候就再次在队列末尾添加标识同时取当前队列第一个元素
//前提是队列不为空 当队列为空且处理到标识 就是说明遍历结束了
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int INF = 55555;
        int var;
        TreeNode* tmp = root;
        queue <TreeNode*> gqueue;
        gqueue.push(root);
        var = root->val;

        gqueue.push(new TreeNode(INF));
        while(!gqueue.empty()){
            TreeNode* first = gqueue.front();
            gqueue.pop();
            if(first->val != INF){
                if(first->left != NULL){
                    gqueue.push(first->left);
                }
                if(first->right != NULL){
                    gqueue.push(first->right);
                }
            }
            else{
                if(!gqueue.empty()){
                    gqueue.push(new TreeNode(INF));
                }
                if(!gqueue.empty()){
                    var = gqueue.front()->val;
                }
            }
        }
        return(var);
    }
};