/*
实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
	int tag = 1;
    bool isBalance(TreeNode* root) {
    	if(!root) return true;
    	highofTree(root);
    	if(tag==1) return true;
    	else return false;
    }

    int highofTree(TreeNode* p) {
    	int R,L，high;
    	R = p->left ? highofTree(p->left) + 1 : 0;
    	L = p->right ? highofTree(p->right) + 1 : 0;
    	high = R > L ? R : L;
    	if((R-L)>1||(R-L)<-1){
    			tag = 0;
    			return 0;
    		}
    	return high;
    }
};

//检查二叉树是否为平衡二叉树 
//只要有一个结点不满足条件 就跳出递归 
//只有所有的结点均满足平衡条件 才是平衡二叉树
//思路就是递归遍历每个结点 设立一个tag标志是否出现非平衡结点