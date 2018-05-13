/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };锯齿状层序遍历一颗二叉树：先从左往右再从右往左遍历每一层
 * 奇数层从左往右偶数层从右往左
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>> ();
        queue<TreeNode*> q;
        q.push(root);
        int tag = 1;
        TreeNode* tail = root;
        vector<vector<int>> res;
        vector<int> v;
        while(!q.empty()) {
        	TreeNode* cur = q.front();
        	v.push_back(cur->val);
        	q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        	if(cur == tail) {
                if(tag%2==0) reverse(v.begin(),v.end());//偶数层reverse一下即可
        		tail = q.back();
        		res.push_back(v);
        		v.clear();
                ++tag;
        	}
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> levelT;
        if(!root)
        {
            return levelT;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight=true;

        while(1)
        {
           int qSize=q.size();
            if(qSize==0)
            {
                break;
            }
            vector<int> temp(qSize);
            for(int i=0;i<qSize;i++)
            {
                TreeNode *root=q.front();
                q.pop();
                int index;
                if(leftToRight)
                {
                    index=i;
                }
                else
                {
                    index=qSize-i-1;
                }

                temp[index]=root->val;
                if(root->left)
                {
                    q.push(root->left);
                }
                if(root->right)
                {
                    q.push(root->right);
                }


            }

            leftToRight=!leftToRight;
            levelT.push_back(temp);

        }

        return levelT;

    }
};