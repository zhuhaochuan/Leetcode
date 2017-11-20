/**Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path1->2->3which represents the number123.
Find the total sum of all root-to-leaf numbers.
二叉树的每个结点都是0-9的一个数 
根结点到叶子结点的路径经过的结点组成一个数 
求根节点到所有叶子结点 得到的这样的数的和。
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumNumbers(TreeNode *root) {
    int sum = 0;
    if (root == NULL) return sum;
	return preorderSumNumbers(root, sum);
}

    int preorderSumNumbers(TreeNode* root, int sum) {
    if (root == NULL) return 0;
    sum = sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) 
	 return sum;
    return preorderSumNumbers(root->left, sum) + preorderSumNumbers(root->right, sum);//这里并不是尾递归 还需要等待下层递归的结果出来才能返回
}
};

//这个题目用递归去解决 重点在于计算每一个根到叶路径对应的数值时 、
//并不能采用先得到这个路径的长度在返回计算
//利用sum这个参数 保存当前计算出来的结果 
//上一层的值在这一层权重为10 
//将父亲结点传入的值乘以10 加上当前结点的值 就是当前如果该节点为叶结点的值
//如果当前结点还有孩子 就将sum传入下一层 
//如果没有孩子 就直接返回