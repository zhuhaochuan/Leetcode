/*
分析：找到字符串数组当中字符串的最大公共前缀
那么每一个字符串必须有公共前缀 否则就没有公共前缀
 */

//我的想法就是先将数组元素按照长度递增排序
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(!strs.size()) return res;
        sort(strs.begin(),strs.end(),[](string& a,string& b) {
        	return a.size()<b.size();
        });//如果数组为空 不能sort 还会报错
        for(int i=0;i<strs[0].size();i++) {
        	for(int j=1;j<strs.size();j++) {
        		if(strs[j][i]!=strs[0][i])
        			return res;
        	}
        	res += strs[0][i];
        }
        return res;
    }
};

