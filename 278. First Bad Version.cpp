// Forward declaration of isBadVersion API.
//分析：给出一组产品，如果前一个产品是坏的，那么当前这个也是坏的
//使用最少的次数找到第一个坏的产品
//如果当前判断是好的那么坏的就在后面此时可以二分
//如果当前判断是坏的，那么就出现在前面

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,r = n;
        while(l<=r) {
        	int mid = l + (r - l) / 2;
        	bool tag = isBadVersion(mid);
        	if(!tag) {
        		l = mid + 1;
        	}
        	else {
        		if(mid==1||!isBadVersion(mid-1))
        			return mid;
        		r = mid - 1;
        	}
        }
        return 0;
    }
};