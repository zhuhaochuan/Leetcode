/*
分析：给定两个整数，要求不用乘除法和取模运算，计算出a/b的值，当结果越界的时候输出INT最大值

特例
-2147483648
-1
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor==0) return INT_MAX;
    	if(dividend==-2147483648&&divisor==-1) return INT_MAX;
        long int a = abs(dividend),b = abs(divisor);
        if(a<b) return 0;
        int tag = 1;
        if(dividend>0&&divisor>0||dividend<0&&divisor<0)
        	tag = 0;
        int res = 0;
        while(a>0) {
        	a -= b;
        	res = a>=0?++res:res;
        }
        if(tag) return -res;
        else return res;
    }
};

//采用移位的方式
//求解a/b其实可以看成求解a由b组成的线性组合
//或者简单的来说就是求a由几个b组成或者 a包含几个完整的b
//按照上一种一个一个从a中减去b的方式非常的慢 有多少个b就需要减多少次
//同样的我们可以利用移位的方式使得除数b乘以2的幂(还需要小于被除数)
//这时用被除数减去扩大了的除数，那么我们得到两个信息
//1.被除数包含扩大了2的幂被的除数 那么结果至少包含这2的幂分量
//2.对于剩下的差我们将其作为新的被除数做同样的操作，求出其他的分量
//直到差小于除数 不能再被分解位置
//将所求的所有值相加求和就是我们需要的结果
//这个方法好处在于，每次做差都是减去的除数的2的幂倍 时间复杂度为logn

//令我抓狂的代码
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        long long int a = abs(dividend),b = abs(divisor),res = 0;
        if(a<b) return 0;
        int tag = 1;
        if(dividend>0&&divisor>0||dividend<0&&divisor<0)
        	tag = 0;
        while(a>=b) {
        	int temp = b,i = 1;
        	while(temp<<1<a) {
        		temp <<= 1;
        		i <<= 1;
        		a -= temp;//问题出现在这里
        	}
        	res += i;
        }
        if(tag)
        	return -res;
        else
        	if(res>INT_MAX) return INT_MAX;
        else return res;
    }
};


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return INT_MAX;
        long long int a = abs((long long) dividend),b = abs((long long)divisor),res = 0;
        cout << a << " " << b << endl;
        if(a<b) return 0;
        int tag = 1;
        if(dividend>0&&divisor>0||dividend<0&&divisor<0)
        	tag = 0;
        while(a>=b) {
        	long long int temp = b,i = 1;
        	while((temp<<1)<a) {
        		temp <<= 1;
        		i <<= 1;
        	}
            a -= temp;//应该讲这句放在外面
        	res += i;
        }
        if(tag)
        	return -res;
        else
        	if(res>INT_MAX) return INT_MAX;
        else return res;
    }
};









