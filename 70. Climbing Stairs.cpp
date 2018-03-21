/*
分析：爬楼梯问题，需要攀爬n层楼梯 每次可以爬一层或者两层
需要求得一共几种方式可以爬上顶层
基本想法是 每次在一个位置上有两种方式向上走，前进1或者2
1 2 3 4 5 6 7 8
使用dp[i]表示到达第i层台阶拥有的可能方式总数
那么dp[i] = dp[i-1]+dp[i-2]
初始化：dp[0] = 0 dp[1] = 1 dp[2] = 2
 */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;dp[1] = 1;dp[2] = 2;
        for(int i=3;i<n+1;++i) {
        	dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};