/*
分析：给出一个数n 将这个n拆分成多个平方项之和
平方项是指：1，4，9，16....i^2
求解组成n的所有的平方项之和中最短的长度
13 = 4 + 9
12 = 4 + 4 + 4
1 2 3 4 5 6 7 8 9 10 11 12 13
1 2 3 1 2 3 4 2 1 2  3  3  2
 */

//dp方法，也是一个刷表法，但是是从前往后刷表
class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
     	vector<int> dp(n+1,INT_MAX);
     	for(int i=0;i*i<=n;++i) {
     		dp[i*i] = 1;
     	}
     	for(int a=1;a<=n;++a) {
     		for(int b=0;a + b*b<=n;++b) {
     			dp[a+b*b] = min(dp[a]+1,dp[a+b*b]);
     		}
     	}
     	return dp[n];
    }
};


class Solution {
public:
    bool isSquare(int n) {
        int sqrt_n = (int)sqrt(n);
        return sqrt_n * sqrt_n == n;
    }
    int numSquares(int n) {
        if (isSquare(n))
            return 1;

        while ((n & 3) == 0)
            n >>= 2;
        if ((n & 7) == 7)
            return 4;

        for (int i = 1; i <= (int)sqrt(n); ++i) {
            if (isSquare(n - i * i))
                return 2;
        }

        return 3;
    }
};
