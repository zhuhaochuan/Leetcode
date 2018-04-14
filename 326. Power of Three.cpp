/*
分析：不使用循环和递归实现判断一个数是不是3的幂
3 9 27 81....
cout 默认输出显示的是6位有效数字而不是完全的和原始数值一样 并且采取多余位四舍五入所以4.999999 实际显示出来的是5。。。
所以在和实际的5比较的时候并不会相等。。。。。对于浮点数的显示是有显示精度误差的
当然本身浮点数自己也有精度误差 这关系到浮点数的精度 表示 以及和整型的转换。。。需要总结

 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) return false;
        double a = log(n)/log(3);
        if(abs(log(n)-round(a)*log(3))<exp(-20))
        	return true;
        else return false;
    }
};

//任何一个3的x次方一定能被int型里最大的3的x次方整除
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) return false;
        return n>0?!(1162261467 % n):0;
    }
};

//遇到浮点数一定考虑精度误差 每次使用浮点数计算的结果都有可能出现误差
//计算的次数越多误差积累就会越多，最终将导致与实际逻辑完全不一致的问题
class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);  //有精度问题，不要用以指数2.718为低的log函数
        return (res - int(res) == 0) ? true : false;
    }
};

// log(243) = 5.493061443340548    log(3) = 1.0986122886681098
//    ==> log(243)/log(3) = 4.999999999999999

// log10(243) = 2.385606273598312    log10(3) = 0.47712125471966244
//    ==> log10(243)/log10(3) = 5.0

