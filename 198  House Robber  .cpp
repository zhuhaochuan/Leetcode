/*
分析：给出一个非负数组
每个元素代表一定的金额数量，可以选择某些房间 但是一旦选择了相邻的两个房间就会触发警报
要求在不触发警报的前提条件下，可以获得最大的金额
2 1 1 2
2 1 3 4
基本想法就是：
还是采用一个dp[i] 表示到当前房间的时候获取的最大的金额
dp[i] = max{dp[0],...,dp[i-2]} + nums[i]
需要采用一个变量max去保存前面的最大值
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        int len = nums.size();
        vector<int> dp(len+1);
        int m = 0;
        dp[0] = 0;dp[1] = nums[0];
        for(int i=2;i<=len;++i) {
        	m = max(dp[i-2],m);
        	dp[i] = m + nums[i-1];
        }
        return dp[len-1]>dp[len]?dp[len-1]:dp[len];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<vector<int>> M(nums.size() + 1, vector<int>(2, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            M[i][0] = max(M[i - 1][0], M[i - 1][1]);
            M[i][1] = nums[i - 1] + M[i - 1][0];
        }

        return max(M.back().front(), M.back().back());
    }
};