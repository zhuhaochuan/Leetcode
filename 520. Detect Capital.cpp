/*
判断一个输入的字符串是否满足大写要求
以下几种合法
全部大写
首字母大写
全部小写

 */

class Solution {
public:
    bool detectCapitalUse(string word) {
    	int len = word.size();
    	if(len==1) return true;
    	int tag = 0;
    	if(!isupper(word[0])) {
    		tag = 1;
    	}
        if(tag==1) {
        	for(int i=1;i<len;i++) {
        		if(!islower(word[i]))
        			return false;
        	}
        	return true;
        }
        else {
        	if(isupper(word[1])) {
        		for(int i=2;i<len;i++) {
        			if(islower(word[i]))
        				return false;
        		}
        		return true;
        	}
        	if(islower(word[1])) {
        		for(int i=2;i<len;i++) {
        			if(isupper(word[i]))
        				return false;
        		}
        		return true;
        	}
        }
    }
};

//这个想法比较简单 用计数的方式去描述结果
class Solution {
public:
    bool detectCapitalUse(string word) {

        int capCount = 0;
        for (char c:word) {
            if (isupper(c)) {
                capCount++;
            }
        }
        return !capCount || capCount == word.size() || capCount == 1 && isupper(word[0]) ;
    }
};