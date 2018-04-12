
//两种方式 我的想法是从高位往地位 每一位直接算出其实际的大小
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size(),sum = 0;
        for(int i=0;i<len;++i) {
            sum += (s[i] - 'A' + 1) * pow(26,len-1-i);
        }
        return sum;
    }
};

//另一种做法是每次只是计算出当前位的权重，每次往后乘以一次基数26往左移一位
class Solution {
public:
    int titleToNumber(string s)
    {
        int result=0;
        for(int i=0;i<s.length();i++)
            result=result*26+s[i]-'A'+1;
        return result;

    }
};