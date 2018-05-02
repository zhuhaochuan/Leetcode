class Solution {
public:
    string addBinary(string a, string b) {
       int n = a.size()-1,m = b.size()-1,c = 0;
        string res = "";
        while(m >=0 || n >=0|| c) {
            int temp1 = n>=0?a[n] - '0':0,temp2 = m>=0?b[m] - '0':0;
            if(temp1+temp2+c==1) {
                res = "1" + res;
                c = 0;
            }
            else if(temp1+temp2+c==0) {
                res = "0" + res;
                c = 0;
            }
            else if(temp1+temp2+c==2) {
                res = "0" + res;
                c = 1;
            }
            else {
                res = "1" + res;
                c = 1;
            }
            --m;
            --n;
        }
        return res;
    }
};