/*
序列如下: 1, 1, 2, 5, 11, 24, 53, 117, 258, 569, 1255
我们发现:

5 = 2 * 2 + 1
11 = 5 * 2 + 1
24 = 11 * 2 + 2
53 = 24 * 2 + 5
117 = 57 * 2 + 11
A[N] = A[N-1] * 2 + A[N-3]
找规律得到递推公式
难点在于重复的判断
 */

class Solution {
public:
    int numTilings(int N) {
        if(!N) return 0;
        int mod = 1000000007;
        vector<long long> dp(N+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=N;++i) {
        	dp[i] = dp[i-1] * 2%mod + dp[i-3];
        }
        return dp[N]%mod;
    }
};

