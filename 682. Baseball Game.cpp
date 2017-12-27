/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
这需要上两次的合法的分数
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
需要上一次的合法的分数
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
取消上一次的分数
*/



class Solution {
public:
    int calPoints(vector<string>& ops) {
        if(ops.empty()) return 0;

        int sum = 0;
        stack<string> valid;

        for(auto element : ops) {
        	if(element != "C"&&element!="D"&&element!="+") {
        		valid.push(element);
        		sum += s2i(element);
        	}
        	else if(element == "C") {
        		if(!valid.empty()) {
        			sum -= s2i(valid.top());
        			valid.pop();
        		}
        	}
        	else if(element == "D") {
        		if(!valid.empty()) {
        			int temp = 2*s2i(valid.top());
        			sum += temp;
        			string temps = i2s(temp);
        			valid.push(temps);
        		}
        		else 
        			valid.push("0");
        	}
        	else if(element == "+") {
        		if(valid.size()>=2) {
        			int a = s2i(valid.top());
        			valid.pop();
        			int b = s2i(valid.top());
        			int c = a + b;
        			string temp = i2s(c);
        			sum += c;
        			valid.push(i2s(a));
        			valid.push(i2s(c));
        		}
        	}
        }
        return sum;
    }

    int s2i(string a);

    string i2s(int a);
};

int Solution::s2i(string a) {
	stringstream ss;
	ss<<a;
	int num;
	ss >> num;
	return num;
}

string Solution::i2s(int a) {
	stringstream ss;
	ss<<a;
	string num;
	ss >> num;
	return num;
}

//思路还是比较清晰的但是感觉自己写的有点繁琐 
//对于string和int的转换
//还有不停的出栈入栈的操作时间开销比较大
//耗时13ms

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;

        for(auto x : ops){
            if(x == "C"){
                scores.pop();
            }else if(x == "D"){
                scores.push(scores.top() * 2);
            }else if(x == "+"){
                int prev = scores.top();scores.pop();
                int prev2 = scores.top();scores.pop();
                
                int s = prev + prev2;
                scores.push(prev2); scores.push(prev); scores.push(s);
            }else{
                scores.push(stoi(x));
            }
        }
    
    int ret = 0;
    while(!scores.empty()){
        ret += scores.top(); scores.pop();
    }
    
    return ret;
    }
};//思路和我的想法一致。。。
//人家用的是stoi string的头文件定义的转换string类型为int类型的函数
//最后再加求和。。。



