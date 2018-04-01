/*
分析：找到一个数组当中最长的递增序列的长度。
只要在后面的元素大于等于前一个元素那么就是递增
[10, 9, 2, 5, 3, 7, 101, 18]

 */
//dp o(n*n)的时间复杂度 o(n)的空间复杂度
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size();
        vector<int> dp(n,0);
        int res = 1;
        for(int i=0;i<n;++i) {
        	int max = 1;
        	for(int j=0;j<i;++j) {
        		int temp = nums[i]>nums[j]?dp[j]+1:1;
        		max = temp>max?temp:max;
        	}
        	dp[i] = max;
            res = max>res?max:res;
        }
        return res;
    }
};

//采用二分搜索的方法，时间复杂度优化到o(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i){

            int lo = 0, hi = dp.size();
            while (lo < hi){
                int mi = (lo + hi)/2;
                if (dp[mi] < nums[i]) lo = mi + 1;
                else hi = mi;
            }
            if (hi == dp.size())
                dp.push_back(nums[i]);
            else dp[hi] = nums[i];
        }
        return dp.size();
    }
};