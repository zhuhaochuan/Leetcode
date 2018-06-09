/*
分析：解码字符串将给出编码的字符串解码成原始字符串。
编码的规则是：k[abc] 解码为 k个连续的abc。
k保证是正整数。先构造[]内部的字符串，然后在重复k个拼接构成外部的字符串。
*/

class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        if(!n) return s;
        int num = 0,tag = 0;
        string res,cur;
        for(int i=0;i<n;++i) {
            if(s[i]=='[') {
                if(num==0) {
                    res += cur;
                    cur.clear();
                }
                if(tag) cur += s[i];
                ++tag;
            }
            else if(s[i]==']') {
                --tag;
                if(tag==0) {
                    string temp = decodeString(cur);
                    while(num) {
                        res += temp;
                        --num;
                    }
                    cur.clear();
                }
                else cur += s[i];
            }
            else if(s[i]>='0'&&s[i]<='9') {
                if(num==0) {
                    res += cur;
                    cur.clear();
                }
                if(tag) cur += s[i];
                else num = (10*num + s[i]-'0');
            }
            else {
                cur += s[i];
            }
        }
        return res+cur;
    }
};