/*
牢记动态规划的填表法和刷表法
这个题目就是找到状态转移方程
采用填表的方法使用之前的信息
填充之后的信息最后计算出来的信息就是我们所需要的答案
 */


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(!cost.size()) return 0;
        int len = cost.size();
        vector<int> dp(len+2);
        dp[0] = 0;dp[1] = cost[0];
        for(int i=2;i<=len;++i) {
        	dp[i] = (dp[i-2]+cost[i-1])<(dp[i-1]+cost[i-1])?(dp[i-2]+cost[i-1]):(dp[i-1]+cost[i-1]);
        }
        dp[len+1] = dp[len-1]<dp[len]?dp[len-1]:dp[len];
        return dp[len+1];
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 0)
            return 0;
        if(cost.size() == 1)
            return cost[0];
        if(cost.size() == 2)
            return min(cost[0], cost[1]);

        int size = cost.size();
        vector<int> dp (size + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < size; i++){
            dp[i] = min(cost[i]+dp[i-2], cost[i]+dp[i-1]);
        }
        dp[size] = min(dp[size-1], dp[size-2]);
        return dp[size];
    }
};