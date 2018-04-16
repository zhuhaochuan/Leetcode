/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };分析：找到一颗二叉树当中有多少条路径的和为目标值
 * 路径不需要经过root或者叶子节点 只需要由上而下
 */



//递归的去实现 并不需要判断当前的节点是不是包含在可行的路径当中，让程序自己去计算
//当前节点为根的可行路径数量等于包含当前节点的可行路径数量加上以左孩子为根的树当中的可行路径数量加上以右孩子为根的可行路径的数量
//只需要实现怎么得到包含一个节点的可行路径的求法 也是递归的实现 如果当前路径和为目标值就加1，但是不返回继续往下加 直到加到叶子节点
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return helper(root, sum, store, 0);
    }
    int helper(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += helper(root->left, sum, store, root->val) + helper(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }
};