//判断一个string字符串当中含有多少个部分，每个不包含空格的连续子串为一个部分
//Input: "Hello, my name is John"
//Output: 5

class Solution {
public:
    int countSegments(string s) {
        if(!s.size()) return 0;
        int n = s.size(),i = 0,count = 0;
        for(i=0;i<n;++i) {
        	if(s[i]!=' ')
        		break;
        }
        for(int j=i;j<n;++j) {
        	if(s[j]==' '&&s[j-1]!=' ')
        		++count;
        }
        if(s[n-1]!=' ') ++count;
        return count;
    }
};