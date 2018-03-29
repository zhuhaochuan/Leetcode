/*
输入两个字符串判断 一个字符串是否是另一个字符串的字母组成
两个字符串所用字母必须一样 也就是一样长
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> table;
        for(char c : s) {
        	++table[c];
        }
        for(char c : t) {
        	if(table[c]<=0)
        		return false;
        	--table[c];
        }
        return true;
    }
};


class Solution {
public:

    bool isAnagram(string s, string t) {
    int alp[26]={};
    for (int i = 0; i < s.length(); i++)
        alp[s[i] - 'a']++;
    for (int i = 0; i < t.length(); i++)
        alp[t[i] - 'a']--;
    for (int i=0;i<26;i++)
        if (alp[i] != 0)
            return false;
        return true;
   }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        // fill usage of letters in s
        char table[26];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < s.size(); i++)
        {
            table[s[i]-'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            table[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (table[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};