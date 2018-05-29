/*
Input: "PPALLL"
Output: False
不能有超过1个的A
不能出现连续2个以上的L
 */

class Solution {
public:
    bool checkRecord(string s) {
        if(!s.size()) return true;
        int n = s.size();
        unordered_map<char,int> table;
        table[s[0]] = s[0]=='L'?0:1;
        for(int i=1;i<n;++i) {
        	if(s[i]=='L') {
        		if(s[i-1]=='L')
        			++table[s[i]];
        		else table[s[i]] = 0;
        	}
        	else
        		++table[s[i]];
        	if(s[i]=='A'&&table[s[i]]>1) return false;
        	else if(s[i]=='L'&&table[s[i]]>=2) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool checkRecord(string& s) {
        int count = 0, cnt = 0;
        for(char& c : s){
            if(c=='L'){
                if(++cnt>2) return false;
            }
            else if(c == 'A'){//其他的字符时将L的计数清零就可以了
                if(++count==2) return false;
                cnt = 0;
            }
            else cnt = 0;
        }
        return true;
    }
};