/*
分析就是给出m个0n个1，问可以构造最多多少个不同的01组合的字符串
这就是一个背包或者装箱问题，就是优化到最优解
那么对于给定的m,n，我们可以得到一个01比m/n


111110000
0 0 10 10 10 10
10 10 10 11 0 0 0 0
 */

//贪心的方法 不适合
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(!strs.size()) return 0;
        sort(strs.begin(),strs.end(),[](const string a,const string b){
        	if(a.size()>b.size())
        		return true;
        	else return false;
        });
        int res = 0, tag = 1;
        for(auto each : strs) {
        	if(each.size()>(m + n)) continue;
        	for(auto s : each) {
        		if(s == '0' && m - 1 >=0)
        			m -= 1;
        		else if(s == '1' && n - 1 >=0)
        			n -= 1;
        		else {
        			tag = 0;
        			break;
        		}
        	}
        	if(tag) ++res;
        	tag = 1;
        }
        return res;
    }
};


static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0);return 0;}();
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(!strs.size()) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto s : strs) {
        	int zeros = 0, ones = 0;
        	for(auto c : s) {
        		if(c == '0') ++zeros;
        		if(c == '1') ++ones;
        	}
        	for(int i=m;i>=zeros;--i) {
        		for(int j=n;          xxx    j>=ones;--j)
        			dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
        	}
        }
        return dp[m][n];
    }
};