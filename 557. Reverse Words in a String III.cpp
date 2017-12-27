//Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//保持原来的空格和单词的顺序

//这道题目的思路很简单 就是使用栈 
//遍历整个字符串 只要不是空格就入栈
//是空格就将栈内元素逐个出栈 再添加空格
//再对最后一个没有空格结尾的单词进行特殊处理 
//也就是将栈内清空

//时间26ms
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string ans;
        stack<char> buf;

        for(int i=0;i<len;i++) {
        	if(s[i]!=' ') {
        		buf.push(s[i]);
        	}
        	else if(s[i] == ' ') {
        		while(!buf.empty()) {
        			ans += buf.top();
        			buf.pop();
        		}
        			ans += ' ';
        	}
        }
        while(!buf.empty()) {
        			ans += buf.top();
        			buf.pop();
        		}
        return ans;
    }
};


//19ms 的代码 
//怪不得快 这个方法不需交换所有的字符或者是生成一个新的字符串
//通过空格的位置i去定位各个单词的首字符和尾字符的位置 再将其逐个交换
class Solution {
public:
    string reverseWords(string s)
    {
        int spaceIdx = -1;
        const int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ' || i == n - 1)
            {
                if (i == n - 1)
                    i++;
                int l = spaceIdx + 1;
                int r = i - 1;
                while (l < r)
                    swap(s[l++], s[r--]);
                spaceIdx = i;
            }
        }
        return s;
    }
};

