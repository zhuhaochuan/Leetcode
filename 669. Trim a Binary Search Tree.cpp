/*
Given a binary search tree and the lowest and highest boundaries as L and R,
trim the tree so that all its elements lies in [L, R] (R >= L).
You might need to change the root of the tree, so the result should
return the new root of the trimmed binary search tree.
 */


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//思路就是 对于每一个节点 如果这个节点的value在 （L,R）之间那么就需要递归的对其左右子节点进行
//判断 ，如果当前的节点的value >= R 则不用进入其右节点 只要递归的判断其左孩子节点
//同理当前节点的value <= L 那么只要递归的判断其右节点即可。

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
    	if(!root) return root;

    	if(root->val>=L&&(root->val)<=R) {
    		if(root->left)
    			root->left = trimBST(root->left,L,R);
    		if(root->right)
    			root->right = trimBST(root->right,L,R);
    		//return root;
    	}
    	else if(root->val>R) {//我这里加了对于子节点为空的判断。。。有点多余
    		if(root->left)
    			return trimBST(root->left,L,R);
	    	else
	    		return NULL;
    	}
    	else if(root->val<L) {
	    	if(root->right)
	    		return trimBST(root->right,L,R);
	    	else
	    		return NULL;
    	}
    	return root;//将返回放在最后 居然效率提高很多？why？？？？
    }
};


//下面是别人同样的思路的答案。。
//写法比我的简洁。。。。。。
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root==NULL)
            return NULL;

        if(root->val<L){
            return trimBST(root->right,L,R);
        }

        if(root->val>R){
            return trimBST(root->left,L,R);
        }
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }
};


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;

        if(root->val < L) root = trimBST(root->right, L, R);
        else if(root->val > R) root = trimBST(root->left, L, R);
        else{
            root->right = trimBST(root->right, L, R);
            root->left = trimBST(root->left, L, R);
        }


        return root;
    }
};