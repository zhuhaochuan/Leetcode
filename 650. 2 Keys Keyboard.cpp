/*
分析：mdzz这道题目还是没有想通
首先是o(n^2)的dp方法：
dp[i]代表长度为i的时候最少的操作数，长度i如果可以被小于i的数j整除，
那么就是表示可以之间粘贴多个长度为j的串形成。
所以dp[i] = min(dp[j] + i/j)
为什么加上i/j呢，因为我们需要1次复制加上i/j-1次粘贴，一共i/j次额外操作。
现在只需要遍历所有的i和小于i的j，依次填表就可以得到最终的答案。
 */

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,INT_MAX);

        dp[0] = dp[1] = 0;

        for(int i=2;i<n+1;++i){
            for(int j=1;j<i;++j){
                if(i%j==0){
                    dp[i] = min(dp[i], dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};


/*
加深对于题目的理解，可以将题目转换成一个等价问题
多的我就不再这里描述，具体可以看官方的解答。
重点是，将n展开成多个素数的乘积，这些素数的和就是我们需要的答案。
质数就是素数，质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数。
就从最小的质数2开始循环取余如果余数为0，就将n处以这个因子，继续取余，如果余数不为0，
则将因子加1，继续判断直到n小于2
 */
class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        int d=2;
        while(n>1)
        {
            while(n%d==0)
            {
                ans+=d;
                n/=d;
            }
            d++;
        }
        return ans;
    }
};