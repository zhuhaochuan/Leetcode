/*
分析：每一节台阶可以放i个硬币给出n个硬币问可以放满几节台阶
也就是等差数列求和公式 求解一个二次函数
注意的地方是输入的n是32位有符号数，如果出现对于n的加减乘除可能会出现溢出的情况
所以再出现与n运算的地方需要显示的或者隐式的将n转化为long long 类型
隐式类型转换：
部分数据类型之间是可以进行隐式转换的
所谓隐式转换，是指不需要用户干预，编译器私下进行的类型转换行为
基本数据类型 基本数据类型的转换以取值范围的作为转换基础（保证精度不丢失）
都满足了一个基本原则：低精度 –》 高精度转换。
低精度到高精度的隐式转换会发生 否则不会发生，只能使用强制类型转换，强制类型转换会损失精度
C++中提供了explicit关键字，在构造函数声明的时候加上explicit关键字，能够禁止隐式转换。

给出一个小数，C++中默认它是什么类型的？
浮点数默认类型为double，加上“f”后缀可以强制指定为float。
用 cout << typeid(XXXX).name();
 */

class Solution {
public:
    int arrangeCoins(int n) {
        if(!n) return 0;
        if(n==1) return 1;
        int res = sqrt(0.25+2.0*n)-0.5;//这里隐式类型转换成double
        return res;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        return floor(sqrt(8*static_cast<double>(n) + 1)/2.0 - 0.5);//floor 取下界
    }
};

//思路采用夹逼定理去逼近这个解。。。。做法就和二分搜索一样了
class Solution {
public:
    int arrangeCoins(int n) {
        //return (int)(-1 + sqrt(1 + 8*long(n)))/2;
        if(n <= 1) return n;
        long start = 1, end = n;
        while(start < end){
            long mid = start + (end-start)/2;
            if(mid*(mid+1)/2 <= n) start = mid+1;
            else end = mid;
        }
        return start -1;
    }
};