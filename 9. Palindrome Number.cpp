/*
分析：负数肯定不是回文数
	不能使用额外的空间
	10001
	1001
	1010
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int l = x, r = 0;
        while (l) r = r * 10 + l % 10, l /= 10;
        return r == x;
    }
};

//想法很全面的答案
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;//所有对于10余数为0的特殊情况都被考虑到了
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};