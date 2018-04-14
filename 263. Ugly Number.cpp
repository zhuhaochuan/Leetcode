


class Solution {
public:
    bool isUgly(int num) {
        if(num==1) return true;
        int tag = -1;
        while(num!=tag&&num>1) {
            tag = num;
            if(num%2==0)
                num /= 2;
            if(num%3==0)
                num /= 3;
            if(num%5==0)
                num /= 5;
        }
        return num==1;
    }
};