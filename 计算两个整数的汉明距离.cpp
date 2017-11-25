class Solution {
public:
    int hammingDistance(int x, int y) {
    	int temp = x^y;
    	int ans = 0;
        for(int i=0;i<32;i++) {
        	ans += (temp>>i)%2;
        }
        return ans;
    }
};

//有点意思的解法
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};