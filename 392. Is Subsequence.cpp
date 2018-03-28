/*
分析：这道题目是一个字符串匹配的变形题
匹配串当中可以剔除一些字符但是不可改变原始字母的顺序
如果能够出现和模式串形同的字符串就说明匹配成功
s = "abc", t = "ahbgdc"
这不是简单的匹配问题
只要模式串当中的字母在匹配串当中按照顺序出现即可
所以至少应该遍历一遍匹配串，
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>=t.size()) return s==t;
        int j = 0;
        for(int i=0;i<t.size();i++) {
        	if(t[i]==s[j])
        		++j;
        }
        return j==s.size();
    }
};


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int s_index=0;
        for(int i=0;i<n&&s_index<m;i++)
            if(t[i]==s[s_index])
                s_index++;
        return s_index==m;
    }
};

class Solution {
public:
	bool isSubsequence(string&s, string&t) const {
		int ls = (int)s.length(), lt = (int)t.length();
		if(ls <= lt) {
			if (ls == lt) { return s == t; }
			char * ps = &s[0], *pe = ps + ls;
			size_t index = 0;
			while (ps < pe) {
				index = t.find(*ps++, index);
				if (index != string::npos) { ++index; }
				else { return false; }
			}
			return true;
		}
		return false;
	};
};