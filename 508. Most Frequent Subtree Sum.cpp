/**
 * 分析：找到出现次数最多的子树和 如果出现平局就将所有的结果输出
 *想法：递归的方法 就是遍历所有的节点 将所有节点代表的子树的值得结果插入一个map当中 第一次出现初值为1 之后依次加1
 *最后遍历一遍当前的map 输出value最大的那个
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	unordered_map<int,int> m;//不需要排序
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        finds(root);
        int max = 1;
        for(auto each : m) {//找到出现最多的次数
        	if(each.second>max) {
        		max = each.second;
        	}
        }
        for(auto each : m) {//再次遍历map将所有出现次数一致的加入res
        	if(each.second == max)
        		res.push_back(each.first);
        }
        return res;
    }

    int finds(TreeNode* root) {
    	if(!root) return 0;
    	int L = finds(root->left);
    	int R = finds(root->right);
    	int sum = root->val + L + R;
    	if(m.find(sum)!=m.end())
    		m[sum]++;
    	else
    		m[sum] = 1;
    	return sum;
    }
};


//在递归的过程中求出最大频率
//想法一致
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int>counts;
        int maxCount = 0;

        sumPostOrder(root, counts, maxCount);
        for(auto count : counts){
            if(count.second == maxCount) res.push_back(count.first);
        }
        return res;
    }

    int sumPostOrder(TreeNode *node, unordered_map<int,int> &counts, int &maxCount){
        if(!node) return 0;

        int sum = node -> val;
        sum += sumPostOrder(node -> left,  counts, maxCount);
        sum += sumPostOrder(node -> right, counts, maxCount);
        ++counts[sum];
        maxCount = max(maxCount, counts[sum]);
        return sum;
    }
};