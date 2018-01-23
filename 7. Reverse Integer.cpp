/*
Given a 32-bit signed integer, reverse digits of an integer.
给出一个32位的整数 得到这个数的翻转数 正负号也要保持
如果翻转的数溢出了就输出0
32 位的系统有符号数的范围是
 */

//傻逼方法 能不中间转换就不中间转换 开销太大了。。。
class Solution {
public:
    int reverse(int x) {
    	string s = to_string(x); int temp = 0;
        if(x<0)
    	    std::reverse(++s.begin(),s.end());//和当前函数同名 所以声明是标准库的作用域
        else
            std::reverse(s.begin(),s.end());//正数是没有符号的
        try {
            temp = stoi(s);//stoi()函数是定义在string头文件的将字符串转换成int的函数
            //但是这个函数当出现整型溢出的时候回抛出std::out_of_range异常
        }
        catch(std::out_of_range) {//如果出现了std::out_of_range异常就返回0
            return 0;
        }
        return temp;
    }
};


//整数逆序的方式：
class Solution {
public:
	int reverse(int x) {
		long result = 0;//64位的长整型 存储 储存的值不会溢出
		while (x) {//这个操作看到多次了 这里是数逆序的关键
			result = result * 10 + x % 10;//负数取余的问题 有两个解 c++取得是使得商尽量大的余数
			x /= 10;
		}
		//因为result是长整型保存所以直接和32位的最大和最小值比较看是否溢出
		return result < INT_MIN || result > INT_MAX ? 0 : result;
	}
};

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)//如果出现了溢出 temp/10 就和原来的ans不同
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};