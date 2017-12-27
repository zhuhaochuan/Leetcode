//Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//给一个若干个英文单词字符串组成的数组 返回其中每个字母是一行组成的单词



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if(!words.size())	
        	return words;
        int tag = 0;
        vector<string> ans;
        int len = words.size();
        for(int i=0;i<len;i++) {
        	for(int j=0;j<words[i].size();j++) {
        		if(j==0)
        			tag = find(words[i][j]);
        		if(find(words[i][j])!=tag)
        			break;
        		if(j==words[i].size()-1)
        			ans.push_back(words[i]);
        	}
        }
        return ans;
    }
    int find(char c);
};

//这里还出现了一个傻逼问题  只考虑了找到了的返回值 却不考虑没找到的情况。。。这个时候这个函数没有返回值。。
//第二个傻逼问题 果然最简单的办法耗时也是最久的。。这样一个个的找在不在 绝对不是个好方法
int Solution::find(char c) {
	string s1("qQwWeErRtTyYuUiIoOpP");
	string s2("aASsdDFfgGHhjJKklL");
	string s3("zZxXcCvVbBbnNmM");
	for(int i = 0;i<s1.size();i++) {
		if(s1[i]==c)
			return 1;
	}
	for(int i = 0;i<s2.size();i++) {
		if(s2[i]==c)
			return 2;
	}
	for(int i = 0;i<s3.size();i++) {
		if(s1[i]==c)
			return 3;
	}
    return 0;
}



//妈的 一开始我就是类似的想法  利用哈希表的快速定位 这样查找时间为常数时间 
//但是 。。。map用的不熟。。。就没想用。。。难受 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        class uTol{
          public:
            char easytolow(char in){
              if(in <= 'Z' && in >= 'A'){
                  return in - ('Z' - 'z');
              }
              return in;
            }  
        };//如果是大写 就转换成小写 这样就将问题简单化  本身就不需要区分大小写

        unordered_map<char, int> style;
        //构建一个无序的map，将字符映射为整型数 

        //下面是循环的新特性 见怪不怪  这里的letter是只读的不可修改
        //这里的auto自动推导变量应该具有的类型 （需要注意的地方）
        //依据范围的循环 不需要给出明确的循环开始和结束的条件 可以使得代码的可读性增强很多
        for(auto letter:"qwertyuiop"){
            style[letter] = 1;//返回对应关键字的值得引用 这里直接修改对应的值
        }
        for(auto letter:"asdfghjkl"){
            style[letter] = 2;
        }
        for(auto letter:"zxcvbnm"){
            style[letter] = 3;
        } 
        //将所有对应行的字符全部映射为同一个数字
        uTol ul;
        vector<string> result;
        for(auto word: words){
            int category = style[ul.easytolow(word[0])];
            //第一个字符的类别就是剩下的基准
            bool isAllsame = true;
            for(auto letter:word){
                if(style[ul.easytolow(letter)] != category){
                    isAllsame = false;
                    break;
                }
            }
            if(isAllsame){
                result.push_back(word);
            }
        }
        return result;   
    }
};

