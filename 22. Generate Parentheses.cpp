/*
给出一个整数n 得到一个函数 这个函数 生成n对括弧
并且输出所有可能的括弧排列方式
n=3
（）（）（）
（）（（））

（（（ count1
 ）））count2
 sum
如果sum小于0直接返回
如果sum大于0继续
如果sum==0 且count1，count2都为0了表示选取成功添加到res当中

我的想法是采用回溯法 将所有的可能一一枚举出来
那么左括弧就加一 右括弧减一 每个时刻的值必须大于等于0 不可为负数

 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(!n) return res;
        findAll(n-1,n,1,res,"(");
        return res;
    }
    void findAll(int count1,int count2,int sum,vector<string>& res,const string& s) {
    	//注意对于传入的常量参数 如果形参是引用的形式则必须加上const修饰否则报错
    	if(sum<0) return;
    	if(!count1&&!count2&&!sum) {
    		res.push_back(s);
    		return;
    	}
    	if(!sum) {
            findAll(count1-1,count2,sum+1,res,s+'(');
            return;
        }
		if(count1>0) findAll(count1-1,count2,sum+1,res,s+'(');
		findAll(count1,count2-1,sum-1,res,s+')');
        return;
    }
};



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        paren(n,0,res,"");
        return res;
    }
private:
    void paren(int n, int m, vector<string>& res, string str){
        if(m == 0 && n == 0){
            res.push_back(str);
            return;
        }
        if(n > 0) paren(n-1, m+1, res, str+"(");//传参数的简洁写法 注意
        if(m > 0) paren(n, m-1, res, str+")");
    }
};