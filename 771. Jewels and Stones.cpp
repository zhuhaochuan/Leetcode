/*
分析：给出一串字母组成的字符串，大小写敏感
找出模式串在母串当中每个元素出现的次数的总和
 J = "aA", S = "aAAbbbb"
 我们不可能一个一个去寻找，这样的时间复杂度为o(m*n)
 采用先将母串每个元素和出现的次数建立一个map，以字母作为key出现的次数作为val
 再次遍历模式串当中每一个元素从map当中将val一个一个提取出来就可以时间复杂度为o(m+n)
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> table;
        for(auto each : S) {
        	if(table.find(each)!=table.end()) table[each]++;
        	else table[each] = 1;
        }
        int res = 0;
        for(auto each : J) {
        	res += table[each];
        }
        return res;
    }
};


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool jems[123];
        memset(jems + 65, false, 58);
        for (int i = 0; i < J.size(); ++i)
            jems[J[i]] = true;
        int res = 0;
        for (int i = 0; i < S.size(); ++i)
            if (jems[S[i]]) ++res;
        return res;
    }
};