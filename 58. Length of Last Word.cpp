//分析：得到字符数组当中最后一个单词的长度
//单词不能包含空格
//如果没有最后一个单词那么就返回0
//从后往前遍历

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(!s.size()) return 0;
        int n = s.size(),count = 0,tag = 0,id = 0;
        for(id=n-1;id>=0;--id) {
        	if(s[id]!=' ') break;
        }
        for(int i = id;i>=0;--i) {
        	if(s[i]!=' ') ++count;
        	else  break;
        }
        return count;
    }
};



class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int count = 0, tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ') --tail;
        while (tail >= 0 && s[tail] != ' ')
        {
            --tail;
            ++count;
        }
        return count;
    }
};