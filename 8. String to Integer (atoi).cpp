/*
分析：将输入的字符串转换成整数输出
需要考虑多种情况的输入
 */

class Solution {
public:
    int myAtoi(string str) {
        long long int res = 0;
    	try {
        	res = stoi(str);
        }catch (std::invalid_argument) {
        	return 0;
        }
        if(res>INT_MAX) return INT_MAX;
        else if(res<INT_MIN) return INT_MIN;
        else return res;
    }
};



class Solution {
public:
    int myAtoi(string str) {
        long long int res = 0;
        if(!(str[0]>=48&&str[0]<=57||str[0]==43||str[0]==45))
            return 0;
        if(str[0]>48){
        	for(int i=0;i<str.size();i++) {
	    		if(res>INT_MAX) return INT_MAX;
	    		if(str[i]==32) break;
	    		if(!isdigit(str[i]))
	    			return 0;
	    		else {
	    			res = res*10 + str[i]-48;
	    		}
	    	}
	    }
	    else {
	    	for(int i=1;i<str.size();i++) {
	    		if(res>INT_MAX) return INT_MAX;
	    		if(!isdigit(str[i]))
	    			return 0;
	    		else {
	    			res = res*10 + str[i]-48;
	    		}
	    	}
	    	if(str[0]==45) res = -res;
	    }
	return res;
    }
};

//string的一些内置的操作方法
class Solution {
public:
    int myAtoi(string str) {
        int i = str.find_first_not_of(' '), s = 1;//找到第一个不是空格的元素的位置
        long res = 0;
        if(str[i]=='+'||str[i]=='-')
            s = (str[i++]=='+')?1:-1;
        while(isdigit(str[i])) {
            res = res*10 + (str[i++]-'0');
            if(res>INT_MAX) return s>0?INT_MAX:INT_MIN;
        }
        return s*res;
    }
};