/*
分析：判断输入字符串中的括号是否合法
输入的字符只有括号 () [] {}
每一组括号必须正确的关闭 也就是出现左括号必须出现与之对应的右括号
在每一对括号之间的括号必须完成配对，不可出现交叉 ([)]
([])
想法的话 使用栈这种数据结构去实现
如果最后是合法的那么最后栈一定为空

很简单的 利用栈实现的字符匹配问题
 */

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        if(!s.size()) return true;
        stack<char> stac;
        stac.push(s[0]);
        for(int i=1;i<s.size();i++) {
        	if(s[i]==')'&&stac.top()=='('||s[i]==']'&&stac.top()=='['||s[i]=='}'&&stac.top()=='{') {
        		stac.pop();
        	}
        	else stac.push(s[i]);
        }
        if(stac.size()) return false;
        else return true;
    }
};