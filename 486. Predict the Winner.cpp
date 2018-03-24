/*
分析：给出一个非负整型数组 两个玩家进行游戏
按照顺序每次只能从数组首位选取一个数，最后得分最大的人获胜，每个人都会选择最大化自己分数的选择，平分情况下1号获胜
[1, 5, 233, 7]
可以先计算所有元素的总和 求出获胜应该得到的最低分如果1号选手得分大于等于这个最低分数那么就获胜


这道题目很难。。。没有思路
这道题关键在于对于状态转移方程的寻找：
使用dp[i][j]代表原始数组当中下标i-j之间数字可以获得的最大分数
因为1号选手首先选，所以1号的最大得分就是dp[0][n-1]，我们得到这个值之后与所有分数的一半进行比较只要大于等于一半值就算赢。
那么接下来是求解状态转移方程的问题！
dp[i][j] 应该有两种情况
如果当前选手选取nums[i]，那么会得到一个结果；如果当前选手选取nums[j]，同样也会产生一个结果，我们选取两者当中最大的。
1.如果选取nums[i]，那么2号选手只能从i+1...j之间选取，那么2号选手会选取这个区间的最优解，如果2号选手选取nums[i+1],那么剩下的分数就是dp[i+2][j]
如果2号选手选取nums[j]，剩下的分数就是dp[i+1][j-1]，这两种情况的最小值就是1号接下来可以获得的分数。那么当前1号可以获得分数是
nums[i] + min(dp[i+1][j-1],dp[i+2,j])
2.同理可知当1号选取nums[j]一号可以获得的分数是：nums[j] + min(dp[i+1][j-1],dp[i][j-2])
最终dp[i][j] = max(nums[i] + min(dp[i+1][j-1],dp[i+2,j]),nums[j] + min(dp[i+1][j-1],dp[i][j-2]))
这样我们就很成功的得到了状态转移方程！但是这只是第一步！
这个dp[][]矩阵是一个二维的问题，怎么去填表也就是更新是一个问题。我选择画图举例分析计算顺序。
首先我们可以尽量多的初始化dp矩阵，dp[i][i]表示长度为1的最大选取分数，必然就是nums[i]，dp[i][i+1]长度为2的最大选取分数必然为max(nums[i],nums[i+1])
那么我们可以初始化出对角线以及上半部分对角线的值，其余值初始化为0.
假设i = j = 4 我们需要得到的就是dp[0][3] 下图当中为1的表示已知值为0的表示未知。
根据状态转移公式，dp[i][j]的值需要先计算出dp[i+1][j-1],dp[i+2][j],dp[i][j-2]，显然要求友上角的值需要求出从右上往左下数第2个对角线上元素的值。
刚好我们已经有了主对角线和上方次对角线的值，只需要从中间往上逐个计算出各个对角线的元素值就能够最终计算出右上角元素的值。
最终确定的更新方式是从上往下按照对角线方式更新，需要2重循环，i从0开始，j从2开始，由于更新对角线元素所以初试位置为dp[0][2]每次i++，j++
这种更新方式需要设立一个额外变量表示层数l，初始位置对角线为第0层次对角线为第1层，我们从第2层开始更新
for(int l = 2;l<n;l++) {
	for(int i=0;i<n-l;i++) {
	j = i + l;
	状态方程。。。。
	}
}
对角线更新方式需要记住，尤其在二维dp的填表法当中算是比较复杂但是也尤为常见的方式。
  1 1 0 0
  0 1 1 0
  0 0 1 1
  0 0 0 1
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()<3) return true;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n));//二维动态数组的初始化
        float sum = nums[n-1];
        for(int i=0;i<n-1;++i) {
        	sum += nums[i];
        	dp[i][i] = nums[i];
        	dp[i][i+1] = max(nums[i],nums[i+1]);
        }
        dp[n-1][n-1] = nums[n-1];
        sum /= 2;
        for(int l=2;l<n;++l) {
        	for(int i=0;i<n-l;++i) {
        		int j = i + l;
        		dp[i][j] = max(nums[i] + min(dp[i+1][j-1],dp[i+2][j]),nums[j] + min(dp[i+1][j-1],dp[i][j-2]));
        	}
        }
        return dp[0][n-1]>=sum?true:false;
    }
};


//基本同样的思路 就是将dp[i][j]看成i-j这段区间的最大分数减去剩下区间最大分数的最大值 如果最后dp[0][n-1]大于等于0就表示1号玩家可以赢
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        for(int i = 0; i < nums.size(); i++) dp[i][i] = nums[i];
        for(int l = 1; l < nums.size(); l++){
            for(int i = 0; i+l < nums.size(); i++){
                dp[i][i+l] = max(nums[i] - dp[i+1][i+l], nums[i+l] - dp[i][i+l-1]);
            }
        }

        return dp[0].back() >= 0;
    }
};






class Solution {
public:
    //note:平局也返回true
    bool PredictTheWinner(vector<int>& nums) {

        //dp[i][j]表示玩家1从i到j的能选到的最大值之和
        int n = nums.size();

        int dp[n][n] = {0};

        //当只有一个数或两个数时，玩家1因为先选，肯定能赢（或平局）
        if(n == 1 || n == 2)
            return true;

        //计算整个序列的数之和
        int sum = 0;
        for(auto a : nums)
            sum += a;

        for(int i = 0; i < n - 1; i++) {
            //len = 1的情况
            dp[i][i] = nums[i];
            //len = 2的情况
            dp[i][i + 1] = max(nums[i], nums[i + 1]);
        }
        dp[n - 1][n - 1] = nums[n - 1];

        //从len = 3开始枚举
        for(int len = 3; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] + min(dp[i + 1][j - 1], dp[i + 2][j]), nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }

        //若玩家1选的值之和大于等于全部和的一半，则胜出（或平局），sum + 1是为了处理sum为基数的情况，如：[1,3,1]
        if(dp[0][n - 1] >= (sum + 1) / 2)
            return true;
        else return false;

    }
};