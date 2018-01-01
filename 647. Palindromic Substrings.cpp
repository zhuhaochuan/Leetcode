/*
分析：计算一个字符串中回文子串的个数
如果一个字符串从左向右写和从右向左写是一样的,这样的字符串就叫做palindromic string
即使子串字符相同但是起始和结束的位置不同也算不一样

发现规律 这样的单一字符组成的子串的字符数和带来的可能数的关系
S(n+1)-S(n) = n+1
差是个等差数列
得出S(n+1)-1 = (n+3)n/2
S(n+1) = (n+3)n/2 + 1
S(n) = (n+2)(n-1)/2 +1

aba这样的。。。
aabaa..
abba 设置一个栈去维护 当当前元素和栈顶元素相同时 pop栈顶元素 当栈为空说明出现了这样的杂情况 sum+1
需要设置一个tag表示 因为要区分与全部相同的情况
caabaad
我觉得去找符合情况的可能数太多太麻烦了
不如去找什么情况下我们可以直接判定这个子串不满足要求
就是说没有考虑非单一字符组成的对称情况
--------------------------------
关键问题还是没找到问题的本质
什么是回文子串？就是对称嘛 对称什么最关键？就是对称中心！
那么这里的对称有几种类型？
两种
一种是偶数个字符组成对称
另一种是奇数个字符组成对称
分类讨论 偶数个的时候对称中心其实为中间两个 奇数个的时候为中间的那一个
aabbaac
aabbbaa
 */

class Solution {
public:
    int countSubstrings(string s) {
        if(!s.size()) return 0;
        s.push_back('/n');
        int sum = 0;
        int l = 0;
        char cur = s[0];
        for(auto each : s) {
        	if(each == cur) {
        		l++;
        	}
        	else {
        		sum += findCount(l);
        		l = 1;
        		cur = each;
        	}
        }
        return sum;
    }
    int findCount(int l);
};

int Solution::findCount(int l) {
	return (l+2)*(l-1)/2 + 1;
}
//法1 从中心向外扩展的思路
int countSubstrings(string s) {
    int res = 0, n = s.length();
    for(int i = 0; i < n; i++){//遍历整个字符串
        for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
        	res++; //substring s[i-j, ..., i+j]  子串长度为2j+1
        for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)
        	res++; //substring s[i-1-j, ..., i+j] 子串的长度为2j+2
    }
    return res;
}

int countSubstrings(string s) {
    int res = 0, n = s.size();
    res = n;
    for(int i = 1; i < n; i++){//遍历整个字符串
        for(int j = 1; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
        	res++; //substring s[i-j, ..., i+j]  子串长度为2j+1
        for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)
        	res++; //substring s[i-1-j, ..., i+j] 子串的长度为2j+2
    }
    return res;
}

int countSubstrings(string s) {
    int num = s.size();

    for(float center = 0.5; center < s.size(); center += 0.5) {

        int left = int(center - 0.5), right = int(center + 1);

        while(left >= 0 && right < s.size() && s[left--] == s[right++])
            ++num;
    }//差2和差1 差2是奇数差1是偶数
    return num;
}

//法二 DP 动态规划的方法
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<int>> dp(n, vector<int> (n));
        for ( int end = 0; end < n; ++end ) {
            dp[end][end] = 1;
            ++count;
            for ( int start = 0; start < end; ++start ) {
                if ( s[start] == s[end] && (start+1 >= end-1 || dp[start+1][end-1])) {
                    dp[start][end] = 1;
                    ++count;
                }
            }
        }
        return count;
    }
};