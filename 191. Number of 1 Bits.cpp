/*
分析： 输入一个无符号的32位数 计算其二进制表示当中有几个1
 */

//我采用的又是一个比较常规的方法，从最低位到最高位逐一遍历如果该位是1计数加一
class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int res = 0;
        for(int i=0;i<32;++i) {
        	res += n & 1;
        	n >>= 1;
        }
        return res;
    }
};


//别人的方法
//这个方法之前见到过！
//n & (n-1)法
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};