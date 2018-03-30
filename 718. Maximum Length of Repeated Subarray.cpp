/*
分析：给出两个数组，找出最长公共子数组的长度。
这明显是冻柜的题目
A: [1,2,3,2,1]
B: [3,2,1,4,7]

 */
//属于暴力解法。。。先填充dp[i][j]就是o(n*m)的复杂度
//再找每条对角线 一共n+m条对角线。。。复杂度太高。。
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(),n = B.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;++i) {
        	for(int j=0;j<n;++j) {
        		if(A[i]==B[j]) dp[i][j] = 1;
        		else dp[i][j] =0;
        	}
        }
        int res = 0,sum = 0;
        for(int len=0;len<=m;++len) {
            res = sum>res?sum:res;
            sum = 0;
        	for(int i=0;i<m-len;++i) {
        		int j = i + len;
	        	if(j>=n) break;
	        	if(!dp[i][j]) {
	        		res = sum>res?sum:res;
	        		sum = 0;
	        	}
	        	else sum += dp[i][j];
        	}
        }
        for(int len=1;len<=n;++len) {
            res = sum>res?sum:res;
            sum = 0;
        	for(int i=0;i<n-len;++i) {
        		int j = i + len;
	        	if(j>=m) break;
	        	if(!dp[j][i]) {
	        		res = sum>res?sum:res;
	        		sum = 0;
	        	}
	        	else sum += dp[j][i];
        	}
        }
        return res;
    }
};

//冻柜做法
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(),n = B.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int res = 0;
        for(int i=1;i<m;++i) {
        	for(int j=1;j<n;++j) {
        		if(A[i]==B[j]) dp[i][j] = dp[i-1][j-1] + 1;
        		else dp[i][j] = 0;
        		res = dp[i][j]>res?dp[i][j]:res;
        	}
        }
        return res;
    }
};