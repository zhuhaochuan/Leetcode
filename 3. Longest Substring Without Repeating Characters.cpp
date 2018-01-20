/*
分析：给定一个字符串 得到字符串的最长的所有字符均不相同的子串的长度
子序列 和 子串是不一样的概念
"pwwkew"
a:97
我的想法：这道题是字符串的题并且求最大值情况 采用动态规划的方式
		使用一个map用于查找是否出现
 */
//这种方式被称为sliding window 滑动窗口
//滑动窗口是数组/字符串问题中常用的抽象概念。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0,max = 0;
        unordered_map<char,int> table;
        for(int i=0;i<s.size();++i) {
        	if(table.find(s[i])==table.end()) {
        		res += 1;
        		table[s[i]] = i;
        	}
        	else {
        		res = i - table[s[i]]<res+1?i - table[s[i]]:res+1;
        		table[s[i]] = i;
        	}
        	max = res>max?res:max;
        }
        return max;
    }
};

//这个是事先存好 空间换取时间
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0,max = 0;
        vector<int> table(128,-1);

        for(int i=0;i<s.size();++i) {
        	if(table[s[i]]==-1) {
        		res += 1;
        		table[s[i]] = i;
        	}
        	else {
        		res = i - table[s[i]]<res+1?i - table[s[i]]:res+1;
        		table[s[i]] = i;
        	}
        	max = res>max?res:max;
        }
        return max;
    }
};


//c++中所有的字符包括可显示的和控制字符 的ASCII码在0-127 范围之内分布
//这时候回想为什么c++中的char类型的字符 一个字符占一个字节
//一个字节相当于无符号数的话 表示0-255
//一个字节相当于有符号数的话 表示-128-127
//不论有符号还是无符号char足以涵盖ASCII所有的字符的编码
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
         int n = str.size();
         int ans = 0;
         int vec[128] = { 0 };

         for (int i = 0, j = 0; j < n; ++j) {
             i = max(vec[static_cast<int>(str[j])], i);
             ans = max(ans, j - i + 1);
             vec[static_cast<int>(str[j])] = j + 1;
         }
         return ans;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int flags[256];
        for (int i = 0; i < 256; i++)
            flags[i] = -1;

        int longest = 0;
        int i = 0;
        int collision = -1;
        while (s[i] != 0)
        {
            if (flags[s[i]] != -1)
                collision = (collision > flags[s[i]] ? collision : flags[s[i]]);
            flags[s[i]] = i;
            longest = (i - collision > longest ? i - collision : longest);
            i++;
        }

        return longest;
    }
};