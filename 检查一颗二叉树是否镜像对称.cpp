/**查看一个二叉树是否是镜像对称的
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路就是 利用如果这个二叉树是对称的二叉树 那么该二叉树的中序遍历的结果放在一个数组当中 这个数组也是对称的
//但是有特例 要排除特殊情况
//空间复杂度为O(n)  
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
    	if(!root) return true;
    	if(root->left&&root->right) { //追加判断 排除干扰情况
    		if(root->left->val!=root->right->val)
    			return false;
    	}
    	vector<int> v;
    	travel(root,v);
    	int len = v.size();
    	for(int i = 0;i<(len/2);i++) {
    		if(v[i]!=v[len-1-i])
    			return false;
    	}
    	return true;
    }
    void travel(TreeNode*p,vector<int> &v) {
    	if(!p) return;
    	travel(p->left,v);
    	v.push_back(p->val);
    	travel(p->right,v);
    }
};


//纯种的递归解决
//要判别一棵树是否为镜像对称
//就只需要判别处于对称位置的两个节点是否相等
//其次这两个节点的外侧孩子是否相等 内侧孩子是否相等
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
		if(!root) return true;
        return helper(root->left, root->right);
    }
 
    bool helper(TreeNode *L, TreeNode *R) {
        if (L == NULL && R == NULL)  return true; 
        if (L && R && L->val == R->val) {
            return helper(L->left, R->right) && helper(L->right, R->left);//传递控制作用
        }
        return false;
    }
};



 //先将左子树或者右子树翻转，然后判断左子树和右子树是否相等
    public boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        TreeNode right = reverse(root.right);
        TreeNode left = root.left;
        return TreeEqual(left,right);
    }
//将树翻转
    public TreeNode reverse(TreeNode root){
        if(root == null) return null;
        if(root.left != null) reverse(root.left);
        if(root.right != null) reverse(root.right);
        TreeNode node = root.left;
        root.left = root.right;
        root.right = node;
        return root;
    }
//判断两棵树是否相等
    public boolean TreeEqual(TreeNode root1,TreeNode root2){
        if(root1 == null && root2 == null) return true;
        if((root1 == null && root2 != null) ||(root1 != null && root2 == null)) return false;
        return TreeEqual(root1.left,root2.left) && TreeEqual(root1.right,root2.right) && root1.val == root2.val;
    }