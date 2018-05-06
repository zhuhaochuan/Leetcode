class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        long a = x;
        while(r * r > a) {
            r = (r + a / r) / 2;
        }
        return r;
    }
};

//牛顿迭代法
int sqrt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}

//二分搜索
int sqrt(int x) {
    long long i = 0;
    long long j = x / 2 + 1;
    while (i <= j)
    {
        long long mid = (i + j) / 2;
        long long sq = mid * mid;
        if (sq == x) return mid;
        else if (sq < x) i = mid + 1;
        else j = mid - 1;
    }
    return j;
}