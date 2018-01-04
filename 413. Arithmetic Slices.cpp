/*
分析：找到一个数列中等差数列子序列的个数
这个子序列的长度大于等于3
每个子序列的共差不一定相等

想法就是 遍历整个数组 计算当前的值减去后一个的值
a b c d e f还需要一个变量记录相等的次数 以及一个变量记录当前的差
1 3 1
2 4 3
3 5 6
4 6 10

s(n+1)-s(n) = n-1
s(4) - s(3) = 2
s(n+1)-s(3)=(n+1)(n-2)/2
s(n+1) = (n+1)(n-2)/2 +1
s(n) = (n)(n-3)/2 +1
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int d = 0, count = 0, res = 0;
        d = A[0] - A[1];

        for(int i=1,j=2;j<A.size();) {
        	if(d==A[i] - A[j])
        		count++;
        	else if(d!=A[i]-A[j]||j==A.size()-1) {//傻逼了当到最后的时候并不会进入这个条件判断
        		d = A[i] - A[j];
        		if(count!=0)
        			res += (count+2)*(count-1)/2 + 1;
        		count = 0;
        	}
        	i = j;
        	j++;
        }
        return res;
    }
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int d = 0, count = 0, res = 0;
        d = A[0] - A[1];
        for(int i=1,j=2;j<A.size();j++) {
        	if(d==A[i] - A[j])
        		count++;
        	else {
        		d = A[i] - A[j];
        		if(count!=0) res += (count+2)*(count-1)/2 + 1;
        		count = 0;
        	}
        	i = j;
        }
        if(count!=0)
        	res += (count+2)*(count-1)/2 + 1;
        return res;
    }
};