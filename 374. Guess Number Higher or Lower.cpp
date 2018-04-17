// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);


class Solution {
public:
    int guessNumber(int n) {
        int l = 1,r = n,mid = 1 + (n-1)/2;
        int tag = guess(mid);
        while(tag!=0) {
            //cout << mid <<" " << tag << endl;
        	if(tag==-1) {
        		r = mid-1;//这里必须减1 因为mid已经判断过不是求解的元素 那么闭区间查找就不能放在区间里
        		mid = l + (r-l)/2;
        		tag = guess(mid);
        	}
        	else if(tag==1) {
        		l = mid+1;//这里必须加1
        		mid = l + (r-l)/2;
        		tag = guess(mid);
        	}
        }
        return mid;
    }
};