
//正常的方法去定位在第几个数 第几位
//唯一的简化地方是使用to_string 将数转化为字符串 方便直接取第几位
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1, start = 1;
        long count = 9;
        while (n > len * count) {
            n -= len * count;
            start *= 10;
            count *= 10;
            len++;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};