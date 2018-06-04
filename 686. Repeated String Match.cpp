/*
分析：给出一个字符串A，判断需要多少个A串才能使得B串为A串的子串
求出这个值得最小值，如果不能返回-1
For example, with A = "abcd" and B = "cdabcdab".
什么时候不能匹配：出现A串当中没有出现的字符，顺序无法匹配
肯定需要遍历一遍B数组，
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(!A.size()) return 0;
        if(!B.size()) return A.size();
        int n = A.size(),m = B.size();
        int count = m / (n+0.0)>m/n?m/n+1:m/n,res = count;
        string temp1;
        while(count) {
        	temp1 += A;
            --count;
        }
        if(helper(temp1,B)){
        	return res;
        }
        else if(helper(temp1+A,B)){
        	return res + 1;
        }
        else return -1;
    }

    bool helper(string A,string& B) {
    	return A.find(B)!=string::npos;
    }
};

//一样的思路 最多只需要判断多一个的结果 如果不行之后再多也不行
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string res = A;
        int count = 1;
        while (res.size() < B.size()) {
            res += A;
            count++;
        }
        if (res.find(B) != string::npos)    return count;
        res += A;
        if (res.find(B) != string::npos)    return count + 1;
        return -1;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // 思路1：i代表每次循环开始，A开始的位置（设想"abcd"、"cdabcd", 只有i=2才有可能比对成功）
        /*for(int i = 0, j = 0; i < (int)A.size(); i++, j=0) {
            while(j==-1 || (j < (int)B.size() && A[(i+j)%A.size()]==B[j])) ++j;
            if(j == B.size()) {
                // 此时 i 为 A 开始比对的位置，j显然是B的长度，如：
                // A="abcd", B="cdabcdab", 则i=2, j=B.size()=8，可以发现刚好补上了前面的值，所以只需要判断是否有余数即可
                return (i+j)/A.size()+((i+j)%A.size()!=0?1:0);

            }
        }*/

        vector<int> next(B.size() + 1);
        next[0] = -1;
        for(int i = 0, j = -1; i < B.size(); ) {
            if(j == -1 || B[j] == B[i]) next[++i] = ++j;
            else j = next[j];
        }

        // 思路2：i的含义与思路1相同，代表每次循环开始，A开始的位置（哪怕是i=j-next[j]）。
        //       当next[j]>=0时，此时意味着j可以跳过某些重复比对，直接从next[j]开始。
        //
        //       关键在于：如何判断无论如何加倍A,也无法构成题目要求的串？
        //               当i>=A.size()时，则可以认为无需再比对下去。因为如果i>=A.size(),其实取模后的值本应该早就比对过了
        for(int i = 0, j = 0; i < (int)A.size(); i+=max(1,j-next[j]), j=next[j]) {
            while(j==-1 || (j < (int)B.size() && A[(i+j)%A.size()]==B[j])) ++j;
            if(j == B.size()) {
                // 此时 i 为 A 开始比对的位置，j显然是B的长度，如：
                // A="abcd", B="cdabcdab", 则i=2, j=B.size()=8，可以发现刚好补上了前面的值，所以只需要判断是否有余数即可
                return (i+j)/A.size()+((i+j)%A.size()!=0?1:0);

            }
        }
        return -1;
    }
};