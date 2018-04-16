/*
分析：给出一个数组 最多可以将其分成k个相邻元素组
求出使得所有组平均值的和的最大值
A = [9,1,2,3,9] 3
不知道后面的情况时没办法判断当前最优解是否是全局最优解的一部分
需要分成k个组
dp[i][j] = average(i,j) + max(...)

平均值：一组数当中有大有小 平均值介于min~max之间
最大情况是k==n 那么sum就等于原数组每个元素的和
最小情况是k==1 那么sum等于所有元素的平均值
看做将n个数分成k个数这k个数的平均数最大？

dp[k][i]表示将0-i元素分成k组所得到的最大值
dp[k][i] = max(dp[k-1][i],dp[k-1][j]+average(j,i)) 对于所有的j<i
最终我们需要的结果是dp[k][n-1] 将原始数组分成k组获得的最大值

template <class InputIterator, class T>
   T accumulate (InputIterator first, InputIterator last, T init);
累加函数第三个参数是初始值 这函数模板的返回值类型是由第三个初试值参数的类型决定的如果传入的是0返回值是int如果传入0.0返回值是double
还有一个点就是求解的是[first，last) 左开右闭区间的和
 */

//整个算法的复杂度是o(N*N*K)空间复杂度是o(N*K) 空间复杂度可以进一步优化
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(!A.size()) return 0;
        int n = A.size();
        if(n==K) return accumulate(A.begin(),A.end(),0.0);
        //if(K==1) return accumulate(A.begin(),A.end(),0)/n;这个函数有个坑 这里需要先将和转化为double否则不会隐式类型转换这里会得到的只是int
        vector<vector<double>> dp(K,vector<double>(n,0));
        vector<double> pre(n,0);
        pre[0] = A[0];
        for(int i=1;i<n;++i) pre[i] = pre[i-1] + A[i];
        for(int i=0;i<n;++i) dp[0][i] = pre[i]/(i+1);
        for(int i=1;i<K;++i) {
        	for(int j=0;j<n;++j) {
        		double max_a = 0;
        		for(int t=0;t<j;++t) {
        			double temp = dp[i-1][t] + (pre[j] - pre[t])/(j-t);
                    if(temp>max_a) max_a = temp;
        		}
        		dp[i][j] = max(dp[i-1][j],max_a);
        	}
        }
        return dp[K-1][n-1];
    }
};
