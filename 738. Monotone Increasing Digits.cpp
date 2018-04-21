/*
分析：给出一个整数n找到一个小于等于这个数的最大的单调递增数
Input: N = 332
Output: 299
如果这个数本身就是单调递增数那么直接就是这个数
11182311
11889999

 */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int id = 0,res = 0,pre = 9,t = N,c = 0,idm = -1;
        while(N) {
        	++c;
        	int cur = N%10;
        	N /= 10;
        	if(cur>pre) {
        		id = c;
        		pre = cur - 1;
                idm = cur - 1;
        	}
			else pre = cur;
        }
        if(!id) return t;
        res = (t / int(pow(10,id-1))-1)*pow(10,--id);
        while(id) {
        	res += 9 * pow(10,id-1);
            --id;
        }
        return res;
    }
};



class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i;
        for(i=0;i+1<s.length()&&s[i+1]>=s[i];i++);
        if(i+1<s.length()) {
            for(;i>0&&s[i]==s[i-1];i--);
            s[i]--;
            for(int j=i+1;j<s.length();j++) s[j] = '9';
        }

        return stoi(s);
    }
};