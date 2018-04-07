class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(),c = 1,i = n-1;
        for(i=n-1;i>=0;--i) {
            if(digits[i] + c>9) {
                digits[i] = 0;
            }
            else if(digits[i] + c<=9) {
                digits[i] += c;
                c = 0;
                break;
            }
        }
        if(c==1)
            digits.insert(digits.begin(),1);//注意第一个参数是迭代器
        return digits;
    }
};