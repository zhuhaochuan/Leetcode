/*
分析：判断一个数的二进制数是否每一相邻位都是不同的
1431655766
1010101010101010101010101010110
 1010101010101010101010101010110
    1...00000000000001  曹尼玛溢出了。。。
    有符号数溢出成了一个负数！
    就进不去底下的循环 导致判断出错
    这里可以增加特殊情况或者是将temp声明为无符号数
	这里再模2就等于0。。。、

 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int temp = n>>1,flag = 1;
        temp = n + temp;
      //if(n>1&&temp/2==0)
        if(n>1&&temp/2<1)
            return false;
        while(temp) {
        	flag *= (temp % 2);
        	temp = temp / 2;
        }
        return flag;
    }
};

//标准的方法就是这样
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = -1;

        while(n) {
            int bit = n % 2;

            if(lastBit == bit) {
                return false;
            }

            lastBit = bit;
            n /= 2;
        }

        return true;
    }
};