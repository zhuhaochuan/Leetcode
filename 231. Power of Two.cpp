/*
分析：判断一个数是不是2的幂
 */
//还是使用log10最为合适
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        double a = log10(n) / log10(2);
        return (a-int(a))==0;
    }
};
//考虑2的幂指数只有某一位为1所以与n-1按位相与必然为0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n -1)) == 0;

    }
};

//同样 使用log就出现浮点数的精度误差
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        double a = log(n) / log(2);
        return (a-int(a))==0;
    }
};