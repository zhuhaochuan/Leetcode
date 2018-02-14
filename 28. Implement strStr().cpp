/*
分析：实现一个函数，返回子串在原始字符串出现的首个位置
如果不包含这个子串则返回-1
这是一个字符串匹配的问题
很多种解法，KMP算法应该是最合适的方式

简直恶心至极
遇到这样的报错
free(): invalid next size (fast): 0x00000000028b9c20 ***
说是和内存有关的问题
其实就是访问了超过申请的数组的空间的内存
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(),len2 = needle.size();
        if(len1<len2) return -1;
        if(len2==0) return 0;
        vector<int> next(len2);
        next[0] = -1;
        int i = 0,j = -1;
        //切记这里的限制 由于在里头加1 所以上线并不是len2
        //kmp算法主要就是对于next数组的理解和递推实现
        while(i<len2-1) {
        	if(j==-1||needle[i]==needle[j]) {
        		++i; ++j;
        		next[i] = j;
        	}
        	else j = next[j];
        }
        j = 0;i = 0;
        while(j<len2&&i<len1) {
        	if(j==-1||haystack[i]==needle[j]) {
        		++i; ++j;
        	}
        	else
        		j = next[j];
        }
        if(j==len2) return i-len2;
        else
            return -1;
    }
};

//这就是暴力解法。。。
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        if(!n) return 0;
         for(int i =0;i<h-n+1;i++){
              int j =0;
             for(;j<n;j++){
                 if(haystack[i+j]!= needle[j]){
                     break;
                 }
             }
             if(j==n) return i;
         }
        return -1;
    }
};
