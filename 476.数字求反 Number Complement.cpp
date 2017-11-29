//将传入的整数的二进制数转化为其反码
//输出反码对应的二进制数
//前导0不包括
//比如5 二进制数为0...101 只当做101 
//

class Solution {
public:
    int findComplement(int num) {
    	int cur = num;
    	int i = 0;
    	while(cur>=0) {
    		cur = num - (2<<i);
    		i++; 
    	}
    	return (2<<(i-1)) -1 -num;
    }
};


//学习学习
class Solution {
public:
    int findComplement(int num) {
        //find the highest bit mask it
        int mask = INT_MAX;
        while (mask & num)
            mask <<= 1;
        return ~mask & ~num;
    }
};