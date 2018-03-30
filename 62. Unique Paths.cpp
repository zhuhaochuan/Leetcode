/*
分析：给出一个m*n的方阵，找出从左上角到右下角所有的可行路径。
只能往右或者下走。

 */
//dfs超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        int res = 0;
        dfs(0,0,dp,res,1);
        return res;
    }

    void dfs(int i,int j,vector<vector<int>>& dp,int& res,int tag) {
        //cout << res << endl;
    	if(i>=dp.size()||j>=dp[0].size()) return;
    	tag = tag & dp[i][j];
    	if(i==dp.size()-1&&j==dp[0].size()-1&&!tag) {
            dp[i][j] = 1;
    		++res;
    		return;
    	}
    	else {
            int temp = dp[i][j];
    		dp[i][j] = 1;
    		dfs(i,j+1,dp,res,tag&temp);
    		dfs(i+1,j,dp,res,tag&temp);
    	}
    }
};

//任意一个位置的路径总数
//dp[i][j] = dp[i][j-1] + dp[i-1][j]
//时间复杂度为o(n*m)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;++i) {
        	dp[i][0] = 1;
        }
        for(int j=0;j<n;++j)
        	dp[0][j] = 1;
        for(int i=1;i<m;++i) {
        	for(int j=1;j<n;++j) {
        		dp[i][j] = dp[i][j-1] + dp[i-1][j];
        	}
        }
        return dp[m-1][n-1];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};