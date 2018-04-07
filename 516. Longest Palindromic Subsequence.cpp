/*
分析:最长回文子序列:序列和子串是不同的题目必须注意
要求的是dp[0][n-1];
dp[i][i] = 1
dp[i][j] = dp[i+1][j-1]+2
dp[i][j] = max(dp[i+1][j],dp[i][j-1])
dp[i][j] 表示s[i]-s[j]之间出现的回文子序列的最大长度，并不是说这段长度都是回文子串
而回文子串问题，需要这段长度都是回文子串，才能进行下一步的判断。
 */
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n<2) return n;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-1;++i) {
        	dp[i][i] = 1;
        	dp[i][i+1] = s[i]==s[i+1]?2:1;
        }
        dp[n-1][n-1] = 1;
        for(int len=2;len<n;++len) {
        	for(int i=0;i<n-len;++i){
        		int j = i + len;
        		if(s[i]==s[j])
        			dp[i][j] = dp[i+1][j-1] + 2;
        		else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        	}
        }
        return dp[0][n-1];
    }
};


