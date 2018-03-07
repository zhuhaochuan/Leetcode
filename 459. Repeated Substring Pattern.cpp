/*
"ab ab ab" 这个字符串的话该怎么判断
abc abc abc
怎么判断 这个字符串是一个由重复字符串组成的字符串

 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len%2==1) return false;
        int i = len/2,j = 0;
        while(i<len) {
        	if(s[j]==s[i]) {
        		++i;++j
        	}
        	else break;
        }
        if(i==len)
        	return true;
        else return false;
    }
};

//这里采用的是重复子串的性质 采用构造判断是否相等的方式 时间复杂度为o(n^2)
class Solution {
 public:
     bool repeatedSubstringPattern(string str) {
         int n = str.size();
         for(int i = n/2; i >= 1; i--){//从中间往前遍历，如果是重复子字符串，后面拼接起来肯定等于原string
             int c = 0;
             string s = "";
             if(n % i == 0){
                 c = n / i;//c是指：c个从零到i- 1的子字符串可以拼成原string
            }
            for(int j = 0; j < c; j++){
                s += str.substr(0, i);
            }
            if(s == str){
               	return true;
            }
        }
        return false;
    }
};

//这里采用了KMP中求next数组的思想 使得在o(n)的时间复杂度当中就可以得到结果
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n + 1, 0);
        while (i < n) {
            if (str[i] == str[j]) dp[++i] = ++j;
            else if (j == 0) ++i;
            else j = dp[j];
        }
        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};