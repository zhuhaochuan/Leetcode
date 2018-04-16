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
        		r = mid-1;
        		mid = l + (r-l)/2;
        		tag = guess(mid);
        	}
        	else if(tag==1) {
        		l = mid+1;
        		mid = l + (r-l)/2;
        		tag = guess(mid);
        	}
        }
        return mid;
    }
};