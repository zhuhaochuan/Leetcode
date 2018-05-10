/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *///对于完全二叉树 完全可以使用数组下标的方法进行节点的判定 因为每个节点按照层序遍历的顺序编号
//左孩子的序号是父亲节点的2*i 右孩子节点是父节点的2*i+1
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0,start = 1,end = 1;
        queue<TreeNode*> q;
        queue<int> index;
        index.push(1);
        q.push(root);
        TreeNode* cur = root,*tail = root;
        while(!q.empty()) {
        	cur = q.front();
        	int i = index.front();
        	index.pop();
        	q.pop();
        	if(cur->left) {
        		q.push(cur->left);
        		index.push(2*i);
        	}
        	if(cur->right) {
        		q.push(cur->right);
        		index.push(2*i+1);
        	}
        	if(cur == tail) {
        		res = max(end - start + 1,res);
        		tail = q.back();
        		end = index.back();
        		start = index.front();
        	}
        }
        return res;
    }
};



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root,1});
        int res = 0;
        while(!q.empty()) {
            int n = q.size(), left = 0, right = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* tmp = q.front().first;
                int num = q.front().second;
                if(left==0){
                    left = num;
                    right = num;
                }
                else right = num;
                if(tmp->left)   q.push({tmp->left, 2*num});
                if(tmp->right)   q.push({tmp->right, 2*num+1});
                q.pop();
            }
            if(left == 0) break;
            res = max(right - left + 1, res);
        }
        return res;
    }
};

