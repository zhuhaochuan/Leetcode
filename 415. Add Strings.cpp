/*
分析：给出两个字符串表示的整数 返回他们的和
傻逼debug环境。。。。我是服了
这里是大数相加 不可能将string转换为string再处理绝对溢出 int 65535 long long 是一个10位数好像
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
    	if(!num1.size()) return num2;
    	if(!num2.size()) return num1;
    	long long int a = 0,b = 0;
    	for(auto each : num1) {
            if(each>='0'&&each<='9') {
                a *= 10;
                a += each - '0';
            }
    	}
    	for(auto each : num2) {
            if(each>='0'&&each<='9') {
                b *= 10;
                b += each - '0';
                }
    	}
        cout << a << " " << b << endl;
    	long long int sum = a + b;
        cout << float(a) + float(b) << endl;
    	string res = "";
        if(sum==0) res += '0';
    	while(sum) {
    		char temp = sum%10 + '0';
    		res = temp + res;
    		sum /= 10;
    	}
    	return res;
    }
};


class Solution {
public:
    string addStrings(string num1, string num2) {
    	int m = num1.size(),n = num2.size();
        if(m<n) return addStrings(num2,num1);
        string res = "";
    	int a = 0,b = 0,c = 0,d = m-n;
    	while(m>0||c) {
    		a = m-1>=0?num1[m-1] - '0':0;
    		b = m-d-1>=0?num2[m-d-1] - '0':0;
    		char temp = (a + b + c)%10 + '0';
    		c = (a + b + c) >= 10 ? 1 : 0;
    		res = temp + res;
    		--m;
    	}
    	return res;
    }
};


class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry > 0)
        {
            int sum = 0;
            sum += i >= 0 ? num1[i--] - '0' : 0;
            sum += j >= 0 ? num2[j--] - '0' : 0;
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            res += char(sum + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};





