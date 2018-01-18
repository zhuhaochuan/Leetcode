/*
分析：
比如n=3
[100,1000)这之间的每一位都不同的数有9*9*8个
这样可以得到每一位之间的数的通项 x(n) = 9*9*..*(9-n+2)
再将前面的叠加就得到答案
 */

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, cnt = 9;
        for (int i = 2; i <= n; ++i) {
            cnt *= (11 - i);
            res += cnt;
        }
        return res;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        for (int i=1; i<=n; ++i) {
            sum += helper(i);
        }
        return sum;
    }
    int helper(int n) {
        if (n > 10) return 0;
        int res = 9, factor = 9;
        for (int i=2; i<=n; ++i) {
            res *= factor;
            factor--;
        }
        return res;
    }
};