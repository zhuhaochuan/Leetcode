/*

 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> table;
        for(char e : s) {
        	++table[e];
        }
        for(char e : t) {
        	if(table[e]<=0)
        		return e;
            --table[e];
        }
    }
};

//牛逼 采用将char转换为int类型进行或运算的方式找到单独出现的那个字符
//
class Solution {
public:
	char findTheDifference(std::string s, std::string t)
	{
		int sum = 0;
		for (unsigned int i = 0; i < s.size(); ++i)
		{
			sum ^= s[i];
		}

		for (unsigned int i = 0; i < t.size(); ++i)
		{
			sum ^= t[i];
		}

		return (char)sum;
	}
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        string str = s + t;
        int res = 0;
        for(char& ch: str)
            res ^= int(ch);
        return char(res);
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;

        for(char c: s)
            res ^= c;
        for(char c: t)
            res ^= c;

        return res;
    }
};