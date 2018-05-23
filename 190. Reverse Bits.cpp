//翻转一个32位无符号数
//Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
//return 964176192 represented in binary as 00111001011110000010100101000000.


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n==0) return 0;
        uint32_t res = 0;
        for(int i=0;i<32;++i) {
        	uint32_t temp = n%2;//获取一个二进制数的最后一位的方法，我采用的是最简单的对2取余
        	n = n>>1;
        	res = (res<<1) + temp;//优先级问题，一直都知道，一直都不总结。。
        }
        return res;
    }
};



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;//左移右移也可以使用复合语句进行改变。
            res += n & 1;//也可以直接与1按位与直接得到最后一位是0还是1，位运算的效率更高
            n >>= 1;
        }
        return res;
    }
};