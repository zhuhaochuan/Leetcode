/* 
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//版本1 写复杂了  p == q == NULL的错误太弱智了
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q) return false;
        else if(q==NULL&&p) return false;

        bool tag1 = true,tag2 = true;

        if(p->val==q->val){
        	if(p->left&&q->left)
        		tag1 = isSameTree(p->left,q->left);
        	if(p->left==NULL&&q->left!=NULL||q->left==NULL&&p->left!=NULL) return false;
        	if(p->right&&q->right)
        		tag2 = isSameTree(p->right,q->right);
        	if(p->right==NULL&&q->right!=NULL||q->right==NULL&&p->right!=NULL) return false;
        }
        else return false;
        if(tag1&&tag2) return true;
        else return false;
    }
};

//版本2 根本不需要再次判断当前结点的下一个结点是否为空指针 直接递归传入 不会出现访问空指针的成员的情况
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q) return false;
        else if(q==NULL&&p) return false;
        bool tag1 = true,tag2 = true;
        if(p->val==q->val){
        		tag1 = isSameTree(p->left,q->left);
        		tag2 = isSameTree(p->right,q->right);
        }
        else return false;
        if(tag1&&tag2) return true;
        else return false;
    }
};

//版本3 简化代码  不需要tag标记 只要出现不成立直接返回false 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q||q==NULL&&p) return false;
        if(p->val==q->val){
        		 if(!isSameTree(p->left,q->left)) 
        		 	return false;
        		 else
        		 	return isSameTree(p->right,q->right);
        }
        else return false;
    }
};

// 版本4 再次简化书写代码  && 逻辑判断 当前面的值为false 就不会再判断后面的表达式的值 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL&&q==NULL) return true;
        else if(p==NULL&&q||q==NULL&&p) return false;
        if(p->val==q->val){
         return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        else return false;
    }
};
