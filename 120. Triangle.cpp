/*
分析：找到三角形上的最短和路径 从顶层到底层
每次只能走向下一层的相邻位置
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

 */
//开n*m空间 可以优化
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n<1) return 0;
        if(n==1) return triangle[0][0];
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MIN));
        for(int i=0;i<m;++i) {
        	dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;--i) {
        	for(int j=0;j<triangle[i].size();++j) {
        		dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
        	}
        }
        return dp[0][0];
    }
};


//自底向上 直接使用原始数组不再使用额外空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};

//优化空间使用o(m)空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>& ans = triangle.back();
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j <= i; ++j)
                ans[j] = min(ans[j], ans[j+1]) + triangle[i][j];
        }
        return ans[0];
    }
};