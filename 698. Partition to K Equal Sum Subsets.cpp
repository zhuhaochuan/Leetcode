/*
分析：给出一个非负数组，判断是否可以拆分成k个非空子集，每个子集的和相同
nums = [4, 3, 2, 3, 5, 2, 1], k = 4
如果可以拆分成k个要求的子集那么每个子集的和为sum/k
上面这个例子来说：sum = 20 每个子集的和为5
那么如果出现一个子集满足剩下的sum等于15 k=3 子问题
再出现剩下sum = 10 k=2
sum = 5 k=1
就变成之前的分成2个和相等的子集的问题。。
dp[i]表示得到和为i的可能数
如果dp[sum/k] = k则返回true否则返回false
使用dfs解决：
几个关键问题：这道题目需要判断是否可以拆分成k个要求的子集
这个问题不能转换成只是拆分成2个子集的问题，问题的目标是找到k个
使用dfs的话需要维护一个visited数组标识该元素是否被访问，如果被访问过就需要跳过该元素
当出现一个集合的和达到目标值得时候，是不是一定就是满足的集合？不一定！
因为该集合占用的元素可能可以拆分成集合其他满足该的集合当中所需的元素
这会导致最终判断成false
所以在遍历顺序上必须优先构造长度尽量短的集合，所以应该先将所有元素从大到小排序
先得到大元素的集合，因为较大元素所需的元素更少，其他集合可以选择的可能更多
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end(),greater<int>());
        if(sum%k) return false;
        sum /= k;
        int n = nums.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;++i)
        	if(!visited[i])
        		dfs(nums,k,sum,visited,i);
        return k==0?true:false;
    }

    bool dfs(vector<int>& nums,int& k,int sum,vector<int>& visited,int j) {
    	for(int i=j;i<nums.size();++i) {
            if(visited[i])
                continue;
    		if(sum-nums[i]==0) {
    			visited[i] = 1;
    			--k;
    			return true;
    		}
    		else if(sum-nums[i]>0) {
    			bool tag = dfs(nums,k,sum-nums[i],visited,i+1);
    			if(tag) {
                    visited[i] = 1;
    				return tag;
                }
    		}
    	}
    	return false;
    }
};