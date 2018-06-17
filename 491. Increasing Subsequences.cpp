/*
分析：找出数组当中的所有的递增子序列
注意子序列，不能对于数组进行排序。
[4, 6, 7, 7]
temp : 4 6 7 7

unordered_map unordered_set 查找和插入都是常数时间
但是标准库只实现了 基本数据类型的hash函数
所以一些其他的对象 结构体 或者是容器的hash函数只能自己实现 才能使用上面两个容器
而map 和 set 不是采用的这个数据结构 而是采用的是红黑树的实现 不需要考虑这个问题。
*/


//递归实现
//递归回溯（DFS)找到所有的递增子序列，使用set来自动去除重复的项
//深度优先遍历的实现:
//维护一个v数组 表示当前的一种可能情况 如果当前的元素比这个数组最后一个元素小就跳过直接判断后面的元素
//直到遍历到nums数组的最后一个元素的时候返回。
//深度优先遍历：先往深走，走到头再返回 如何可以继续走就继续走到头，直到所有的地方都被遍历过回到最起点结束。
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(!nums.size()) return vector<vector<int>> ();
        set<vector<int>> s;//最简单的实现使用 set 进行去重复的判断
        vector<int> v;
        helper(nums,s,v,0);
        return vector<vector<int>>(s.begin(),s.end());
    }

    void helper(vector<int>& nums,set<vector<int>>& s,vector<int>& v, int index) {
    	if(v.size()>=2) {//按照要求只有长度大于2的序列才加入到答案当中
            s.insert(v);
        }
    	for(int i=index;i<nums.size();++i) {
    		if(v.size()&&nums[i]<v.back()) {//如果当前的元素的值比v当中的最后一个元素小就直接跳过
                continue;
    		}
            v.push_back(nums[i]);
    		helper(nums,s,v,i+1);
            v.pop_back();
    	}
    }
};


//使用哈希表代替set提高效率
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res, cur(1);
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            int n = cur.size();
            int start = m[nums[i]];
            m[nums[i]] = n;
            for (int j = start; j < n; ++j) {
                if (!cur[j].empty() && cur[j].back() > nums[i]) continue;
                cur.push_back(cur[j]);
                cur.back().push_back(nums[i]);
                if (cur.back().size() >= 2) res.push_back(cur.back());
            }
        }
        return res;
    }
};