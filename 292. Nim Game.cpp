/*
分析：一堆石头 一次一个人只能取1-3个 拿走最后一个石头的获胜
n块石头被取完的次数的范围：最后一次至少取3个

简单点说就是 倒数第二次给对方剩下的个数为4 就能赢否则输

 */

class Solution {
public:
    bool canWinNim(int n) {
    	if(n<=3) return true;
        if(n==4) return false;
        if(n%4<=3&&n%4>=1)
        	return true;
        else return false;
    }
};


//对4取余是不可能大于4的如果余数不为0必然在1-3之间
//抛去第一次取 将对方取一次和我去一次看成一组 每次一组必然可以组成4
//如果总数对4取余为0那么就无法执行第一次取得操作 那么就会输
class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};