//Write a function that takes a string as input and returns the string reversed.

//常规做法 O(N)的时间复杂度
class Solution {
public:
    string reverseString(string s) {
		if(s.empty())	return s;
		string ans;
		for(int i=s.end();i>=0;i--) {
			ans += s[i];
		} 
		return ans;       
    }
};

//这个方法只需要遍历一半的元素 9ms但是还不是最好的
class Solution {
public:
	string reverseString(string s) {
		if(s.empty()) return s;
		int end = s.size()-1;
		for(int i=0;i<end;i++) {
			swap(s[i],s[end]);
			end--;
		}
		return s;
	}
};
//这个swap函数 一个是在算法当中定义的算法 是直接交换两个参数的值 
//string类的成员函数swap 是将参数中的字符串替换当前的字符串
//在oj中调用算法当中的函数 不需要添加对应的头文件
