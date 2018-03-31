/*
分析：给出一个非负数构成的矩阵，找出左上角到右下角的最小权值和。
dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
 */
//这种问题就不用再去补0.这样是不对的
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(!grid.size()) return 0;
    	int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i) {
        	for(int j=1;j<=n;++j) {
        		dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
                cout << dp[i][j] << endl;
        	}
        }
        return dp[m][n];
    }
};


//冻柜解法
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(!grid.size()) return 0;
    	int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<m;++i)
        	dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=1;j<n;++j)
        	dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i=1;i<m;++i) {
        	for(int j=1;j<n;++j)
        		dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
        return dp[m-1][n-1];
    }
};