/*
分析：在1-n当中猜一个数，如果猜不中就需要付出猜的数相应的钱
请问至少需要多少钱才能猜中1-n当中任意一个数
很显然猜每个不同的数的代价是不一样的，所以需要求的是当中最大的那个代价
但是对于每一个特定的数而言，求解到这个数的代价是有一个最小量的。

Minimax极小化极大算法
 */
//递归版本 但是没有记忆中间结果结果超时
class Solution {
public:
    int getMoneyAmount(int n) {
        int res = INT_MAX;
        if(n<=1) return 0;
        helper(1,n);
        return res;
    }

    int helper(int i,int j) {
    	if(j-i+1==3)
    		return i+1;
    	if(j-i+1==2)
    		return i;
        if(j-i+1<2)
            return 0;
    	int res = INT_MAX;
    	for(int k=i;k<=j;++k) {
    		int l = helper(i,k-1) + k;
    		int r = helper(k+1,j) + k;
    		res = max(l,r)<res?max(l,r):res;
    	}
    	return res;
    }
};

//使用一个二维矩阵记忆中间的结果
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        return helper(1, n, memo);
    }
    int helper(int start, int end, vector<vector<int>>& memo) {
        if (start >= end) return 0;
        if (memo[start][end] > 0) return memo[start][end];
        int res = INT_MAX;
        for (int k = start; k <= end; ++k) {
            int t = k + max(helper(start, k - 1, memo), helper(k + 1, end, memo));
            res = min(res, t);
        }
        return memo[start][end] = res;
    }
};



class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=1;i<n;i++){
            dp[i-1][i] = i;
        }
        for(int len=2;len<n;len++){
            for(int i=0;i+len<n;i++){
                int tmp = INT_MAX;
                int j=i+len;
                for(int k=i+1;k<j;k++){
                    int cur  = k+1 + max(dp[i][k-1],dp[k+1][j]);
                    tmp = min(tmp,cur);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[0][n-1];
    }
};