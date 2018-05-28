//分析：1，0，8旋转
//2-5，6-9
//出现其他的数字3，4，7旋转后不合法
//1-10：2，5，6，9
//11-20：12，15，16，19，20

class Solution {
public:
    int rotatedDigits(int N) {
    	int res = 0;
        for(int i=1;i<=N;++i) {
        	if(isval(i)) ++res;
        }
        return res;
    }

    bool isval(int n) {
    	bool tag = false;
    	while(n) {
    		int t = n%10;
    		n /= 10;
    		switch(t) {
    			case 3: return false;
    			case 4:return false;
    			case 7:return false;
    			case 2:tag = true;
    			case 5:tag = true;
    			case 6:tag = true;
    			case 9:tag = true;
    		}
    	}
    	return tag;
    }
};