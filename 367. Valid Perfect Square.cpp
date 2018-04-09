class Solution {
public:
    bool isPerfectSquare(int num) {
        int temp = sqrt(num);
        temp *= temp;
        if(temp>INT_MAX) return false;
        return temp == num;
    }
};


//n^2 - (n-1)^2 = 2n - 1
//不断的减去差值，只要可以减为0说明是平方数
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};