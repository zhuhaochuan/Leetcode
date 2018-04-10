/*
分析：找到一个字符串当中出现的第一个不重复的字母的位置
s = "loveleetcode"

 */

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if(!n) return -1;
        if(n==1) return 0;
        vector<int> table(26,0);
        for(int i=0;i<n;++i) {
            ++table[s[i]-'a'];
        }
        for(int i=0;i<n;++i)
            if(table[i]==1)
                return i;
        return -1;
    }
};