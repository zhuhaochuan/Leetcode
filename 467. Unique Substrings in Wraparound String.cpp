/*
分析：当前子串的长度 可以推出子串含有的个数
还需要一个visited[i][j][k]表示以字母i起始到字母j结尾的长度为k的子串是否出现过 如果出现过就不在计算
 */

// 我们看abcd这个字符串，以d结尾的子字符串有abcd, bcd, cd, d，
// 那么我们可以发现bcd或者cd这些以d结尾的字符串的子字符串都包含在abcd中，
// 那么我们知道以某个字符结束的最大字符串包含其他以该字符结束的字符串的所有子字符串
//看待这个问题的角度 重复的是一个一个字符串 如何能够一次性的计算所有的不重复的结果
//就是将问题独立化 以每一个不同的字母开头或者结尾的字符串必定是不同的字符串 他们的和必然又是包含了所有的情况
//这样一种划分就很有意义
//这样只需要考虑其中最大的长度 就可以
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                ++len;
            }
            else {
                len = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};