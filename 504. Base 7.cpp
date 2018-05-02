class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        string res = "";
        int abs_num = abs(num);
        while(abs_num) {
            int temp = abs_num%7;
            res = to_string(temp) + res;//开销会更大 因为字符串的拼接是形成一个新的字符串之后在拷贝给原始的字符串
            abs_num = abs_num / 7;
        }
        if(num<0)
            res = "-" + res;
        return res;
    }
};

//所以还是一个一个往字符串后面接最后在翻转字符串时间效率更高
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) { return "0"; }
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        string s;
        while (num) {
            int next = num / 7;
            int rem = num % 7;
            s += to_string(rem);//这里并不会产生新的对象，只是对原始的对象进行操作开销非常少
            num = next;
        }
        if (neg) {
            s.push_back('-');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};


class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool neg = false;
        if (num < 0) {
            neg = true;
            num *= -1;
        }
        string rst;
        while(num != 0){
            rst.push_back('0' + num % 7);
            num /= 7;
        }
        if(neg){
            rst.push_back('-');
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};