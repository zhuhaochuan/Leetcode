/*
分析：给出n个气球每个气球有一个得分，分别对应nums[0]...nums[n-1]
附加条件nums[-1] = nums[n] = 1 虽然这两个值物理上不存在
每次可以删除一个气球
每个得分大于等于0
求解得分的最大值
nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
暴力解法：递归寻找每个可能的删除顺序 找=找到最大得分 可以使用dfs
比如：删除nums[i]剩下nums[0]..nums[i-1],nums[i+1]..nusm[n-1] 我们不能确保拿出i之后剩下的最优解加上i的分数就是最优解，这不是一个贪心问题
3n次
3 1 5 8
3 5 40 8 56
3 5 40 5 53

0123 32 213 231 312 3

 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size();
        int coins = 0;
        vector<int> visited(nums.size(),0);
        dfs(nums,visited,coins,0);
        return coins;
    }
    void dfs(vector<int>& nums,vector<int>& visited,int& coins,int points) {
    	int n = nums.size();
    	for(int i=0;i<n;++i) {
    		vector<int> temp_visited = visited;
    		if(temp_visited[i])
    			continue;
    		temp_visited[i] = 1;
    		int l = find_left(nums,temp_visited,i);
    		int r = find_right(nums,temp_visited,i);
    		points += nums[i] * l * r;
    		coins = points>coins?points:coins;
            //cout << i<< endl;
    		dfs(nums,temp_visited,coins,points);
            points -= nums[i]*l*r;
    	}
    	return;
    }
    int find_left(vector<int>& nums,vector<int>& visited,int j) {
    	int i = j-1;
    	while(i>=0) {
    		if(visited[i])
    			--i;
    		else break;
    	}
    	if(i==-1) return 1;
    	else return nums[i];
    }
    int find_right(vector<int>& nums,vector<int>& visited,int j) {
    	int i = j+1;
    	while(i<nums.size()) {
    		if(visited[i])
    			++i;
    		else break;
    	}
    	if(i==nums.size()) return 1;
    	else return nums[i];
    }
};


//如果按照从第一个扎破的气球开始寻找最优解，其实是没办法分析的
//第一个气球的位置，影响到后面气球的情况，每一步的耦合性太高，没办法分析这部分中间的子问题，子问题太多
//如果从最后一个扎破的气球分析，最后一个气球的得分必然是1*nums[i]*1，i将所有的气球分成两部分
//0..i-1 和 i+1..n-1 相当于nums[i]是左侧区间的右墙 也是右侧区间的左墙
//如果在原数组首尾添加两个1作为原始数组的墙，那么左侧区间可以看做0|1...i-1|i，右侧区间看成i|i+1...n|n+1
//一旦这样分解左右两个部分就变成两个相互独立的子问题，这个子问题和原问题一模一样，但是相互独立
//一旦这样拆分，再加上记忆化中间计算
class Solution {
public:
    int divid(vector<int>& nums, vector<vector<int>>& dp, int low, int high)
    {
        if(low+1 == high) return 0;//low-high是个开区间 如果中间没有元素递归返回
        if(dp[low][high] > 0) return dp[low][high];//如果这段区间已经计算过就直接返回
        int ans = 0;
        for(int i = low+1; i < high; i++)
            ans=max(ans, nums[low]*nums[i]*nums[high] + divid(nums, dp, low, i) + divid(nums, dp, i, high));
        dp[low][high] = ans;
        return ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        return divid(nums, dp, 0, nums.size()-1);
    }
};