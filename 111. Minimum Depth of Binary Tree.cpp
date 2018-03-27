/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：给出一颗二叉树，找到最小的深度
 * 递归计算的话需要遍历所有的节点
 * 但是层序遍历不需要遍历所有的节点只需要找到最浅层数即可停止遍历
 * 所以采用层序遍历的方式进行计算
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tail = root;
        int count = 0;
        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	q.pop();
            if(!cur->left&&!cur->right) break;
        	if(cur->left) q.push(cur->left);
        	if(cur->right) q.push(cur->right);
        	if(cur == tail) {
        		tail = q.back();
        		++count;
        	}
        }
        return count+1;//注意加一
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int i = 0;
    while (!Q.empty()) {
        i++;
        int k = Q.size();
        for (int j=0; j<k; j++) {
            TreeNode* rt = Q.front();
            if (rt->left) Q.push(rt->left);
            if (rt->right) Q.push(rt->right);
            Q.pop();
            if (rt->left==NULL && rt->right==NULL) return i;
        }
    }
    return -1; //For the compiler thing. The code never runs here.
}
};

//递归的方式需要递归计算每一个节点的左右孩子的深度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        if(root->left == NULL){
            return 1+minDepth(root->right);
        }else if(root->right == NULL){
            return 1+minDepth(root->left);
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return 1+(l<r?l:r);
    }
};