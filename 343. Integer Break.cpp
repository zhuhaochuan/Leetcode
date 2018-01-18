/*
分析：给定一个2-58的整数 将其拆分成至少两个正整数的和
	求出所有拆分可能中拆分出来的数的最大乘积。
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> d(n,0);
        if(n==2) return 1;
        if(n==3) return 2;
        d[0] = 1;d[1] = 2;d[2] = 3;d[3] = 4;
        for(int i=5;i<=n;i++) {
        	for(int j=2;j<=i/2;j++) {
        		int temp = d[j-1] * d[i-j-1];
        		if(temp>d[i-1]) d[i-1] = temp;
        	}
        }
        return d[n-1];
    }
};


class Solution {
public:
    int integerBreak(int n) {
        // DP
        // dp[i] = max product of int i
        // to get dp[i], find the highest dp[j] * (i - j) from 0 to i;

        vector<int> dp(n + 1, 1);
        for (int i = 3; i < dp.size(); i++) {
            for (int j = 2; j < i; j++) {
                if (dp[j] * (i - j) > dp[i])
                    dp[i] = dp[j] * (i - j);
                if (j * (i - j) > dp[i])
                    dp[i] = j * (i - j);
            }
        }

        return dp[n];
    }
};