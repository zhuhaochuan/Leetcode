/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 分析：构造所有的由1-n组成的BST
 * 先找规律
 * 1:1
 * 2:2
 * 3:5
 * 4:
其基本思想是仅从n-1节点树的结果中构造n个节点树的结果。
以下是我们的做法：只有两个条件：
1）第n个节点是新的根，所以newroot-> left = oldroot;
2）第n个节点不是根节点，我们遍历旧树，每当旧树中的节点有一个右子节点时，我们可以执行：旧节点->右=第n个节点，第n个节点->左=右子节点。
当我们到达树的末尾时，不要忘记我们也可以在这里添加第n个节点。
需要注意的一件事是，每次我们在结果中推送一个TreeNode时，我都会推送根的克隆版本，并立即恢复我对旧节点的操作。 这是因为您可能会多次使用旧树。
 */
class Solution {
    public:
    	//递归的深拷贝一颗树  不能简单的拷贝。。因为传递的都是指针 都是对原始的节点进行操作
        TreeNode* clone(TreeNode* root){
            if(root == nullptr)//nullptr 是空指针常量 c++中区分整数0和空指针的一个关键字
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }

        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res(1,nullptr);

            for(int i = 1; i <= n; i++){

                vector<TreeNode *> tmp;

                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);

                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;

                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode* tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode* target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }

                        tmpold->right = new TreeNode(i);
                        TreeNode* target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };




class Solution {
public:
	TreeNode* clone(TreeNode* root){
            if(root == nullptr)//nullptr 是空指针常量 c++中区分整数0和空指针的一个关键字
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>();

        vector<TreeNode*> dp{NULL};
        for(int i=1;i<=n;++i) {
        	vector<TreeNode*> temp;
        	for(int j=0;j<dp.size();++j) {
        		helper(dp[j],temp,i);
        	}
        	dp = temp;
        }
        return dp;
    }

    void helper(TreeNode* root,vector<TreeNode*>& temp, int idx) {
    	TreeNode* cur = root;
		TreeNode* newroot = new TreeNode(idx);
		newroot->left = clone(cur);
		temp.push_back(newroot);

		while(cur) {
			build(cur,idx,temp,root);
			cur = cur->right;
		}
    }

    void build(TreeNode* cur,int idx,vector<TreeNode*>& temp,TreeNode* old){
    	TreeNode* t = cur->right;//必须保存他的右子树的信息
    	TreeNode* node = new TreeNode(idx);
		cur->right = node;
		node->left = t;
		temp.push_back(clone(old));//必须从头开始深拷贝一个根节点 否则都是一样的。。。
        cur->right = t;//还原现场因为已经改变了树的结构必须还原成原来的样子 否则再怎么做也不对
    }
};