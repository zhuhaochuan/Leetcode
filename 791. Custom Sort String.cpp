/*
分析；使T串的字符顺序和S串一致
S = "cba"
T = "abcd"
Output: "cbad"
 */

class Solution {
public:
    string customSortString(string S, string T) {
        if(!S.size()) return T;
        if(!T.size()) return string ();
        vector<int> tableS(26,0);
        unordered_map<int,string> m;
        for(char c:S) {
        	++tableS[c-'a'];
        }
        string res,temp;
        for(char c:T) {
        	if(tableS[c-'a'])
				m[c-'a'] += c;
			else temp += c;
        }
        for(char c:S) {
            res += m[c-'a'];
        }
        return res + temp;
    }
};