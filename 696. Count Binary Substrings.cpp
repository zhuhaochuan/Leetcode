/*
分析啊；给定一个01序列字符串
求出有多少个0和1相等且都连续的子序列
101010
1110110001
11000
1 2 3 4 5
 */

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(!s.size()) return 0;
        int len = s.size();
        if(len==1) return 0;
        int count = 0, cur = 1;
        int pre = s[0];

        for(int i=1;i<len;i++) {
        	if(pre == s[i]) {
        		cur++;
        		pre = s[i];
        	}
        	else {
        		int temp = 1;
                if(cur!=0) {
                    cur--;
                    count++;
                }
        		while(i+1<len&&s[i+1]!=pre) {//边界处理
        			temp++;
        			if(cur!=0) {
        				cur--;
        				count++;
        			}
        			else {
        				cur = temp;
        				pre = s[i-1];
                        i++;
        				break;
        			}
                    i++;
        		}
                cur = temp;
                pre = s[i];
        	}
        }
        return count;
    }
};

//这个想法很好 只是遍历一遍当前字符串
//用两个变量去保存当前和之前的连续长度
//一旦出现不同就pre=cur cur=1
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, sol = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) cur++;
            else {
                prev = cur;
                cur = 1;
            }
            if (prev >= cur) sol++;
        }
        return sol;
    }
};