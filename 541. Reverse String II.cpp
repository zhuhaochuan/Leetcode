/*
翻转每2k个字符当中前k个字符
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        if(!s.size()||!k) return string ();
        int n = s.size(),i = 0;
        for(i=0;i+k<n;) {
        	reverse(s.begin()+i,s.begin()+i+k);
        	i += 2*k;
        }
        if(i<n) reverse(s.begin()+i,s.end());
        return s;
    }
};


class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2 * k){
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }

        return s;
    }
};