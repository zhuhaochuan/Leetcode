/*对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。

深度：结点的深度即为结点的层次；离根最远结点的层次即为树的深度。 深度是从上往下定义的

高度：规定叶结点的高度为1，其双亲结点的高度等于它的高度加一。 高度是从下往上计算的 
树的高度：等于根结点的高度，即根结点所有子女高度的最大值加一。 递归的定义体现

*/
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
    	int num = vals.size();
    	int ans = log10(num)/log10(2);
    	return ans+1;
    }
};



//虽然可以直接公式算高度，不过也写了个建树顺便算高度的
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int height = 0;//初始化
        buildMinimalBST(vals, 0, vals.size() - 1, height);
        return height;
    }

    TreeNode* buildMinimalBST(vector<int> vals, int start, int end, int& height){
        if(start > end){//递归终止条件
            height = 0;
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(vals[mid]);//根节点
        int left, right;//左右子树
        root->left = buildMinimalBST(vals, start, mid - 1, left);//左子树
        root->right = buildMinimalBST(vals, mid + 1, end, right);//右子树
        height = (left >= right ? left : right) + 1;//计算当前高度
        return root;
    }
};