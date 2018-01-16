/*
分析：给定两个字符串 对两个字符串做删减 使这两个字符串相同
求所有的方式当中所要删除的字符的ASCII码之和最小的值是多少？

比如：s1 = "delete", s2 = "leet"
"let"，"lee" ， "eet",
e<l<t
问题1 如何得到最后的子串？
首先子串的每个出现的字符都必须在两个字符串当中出现。
其次目标是删除最少，那么子串的长度尽量长。



 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
    	int len1 = s1.size(),len2 = s2.size();
    	int dp[len1+1][len2+1] = {0};
    	dp[0][0] = 0;
    	for(int j=1;j<=len2;j++) {
    		dp[0][j] = dp[0][j-1] + s2[j-1];
    	}
    	for(int i=1;i<=len1;i++) {
    		dp[i][0] = dp[i-1][0] + s1[i-1];
    	}

    	for(int i=1;i<=len1;i++) {
    		for(int j=1;j<=len2;j++) {
    			if(s1[i-1] == s2[j-1])
    				dp[i][j] = dp[i-1][j-1];
    			else {
    				dp[i][j] = dp[i-1][j]+s1[i-1]<dp[i][j-1]+s2[j-1]?dp[i-1][j]+s1[i-1]:dp[i][j-1]+s2[j-1];
    			}
    		}
    	}
    	return dp[len1][len2];
    }
};