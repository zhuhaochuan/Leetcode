/*
判断一个数的阶乘尾部有多少个0
也就是判断阶乘中出现了多少个因子5，因为2*5得10
2的个数永远比5多所以只要找5
n/5每次都缩小为原来问题的1/5这是log(n)级别的
 */

class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int res = 0;
        while(n>=5) {
            n = n/5;
            res += n;
        }
        return res;
    }
};