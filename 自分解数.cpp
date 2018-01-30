//所有含有0的数不行
//绝对值小于10的都是
//所有大于10的质数都不是


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> v;
        for(int i=left;i<=right;i++) {
         if(i<10) v.push_back(i);
         else if(i>=10&&i<100) {
           int a = i/10; int b = (i-a*10);
           if(a && b && (i%a) == 0 && (i%b) == 0) v.push_back(i);
         }
         else if(i>=100&&i<1000) {
           int a = i/100; int b = (i-a*100)/10; int c = i-a*100 - b*10;
           if(a && b && c && (i%a) == 0 && (i%b) == 0 && (i%c) == 0) v.push_back(i);
         }
         else if(i>=1000&&i<=10000) { if(i==10000) break;
           int a = i/1000; int b = (i-a*1000)/100; int c = (i-a*1000 - b*100)/10;
           int d = i-a*1000 - b*100 - c*10;
           if(a && b && c && d && (i%a) == 0 && (i%b) == 0 && (i%c) == 0 && (i%d) == 0) v.push_back(i);
         }
        }
        return v;
    }
};

//同样3ms 人家答案简单的不行。
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
     vector<int> result ;

        for(int i = left ; i<= right; i++) {
            int t = i ;
            bool fl  = true;
            while(t) {
                int c = t%10;//得到的是这个数的个位
                t /= 10; //这个十进制数右移一位
                fl = (fl && (c!=0) && (i%c == 0)); //判断每一位
                if(!fl) break;
            }
            if(fl == true) result.push_back(i);
        }
        return result;
    }
};