
//好好分析逻辑 将其转化为标准冻柜
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(n,0);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>0;--i) {
        	dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
        }
        int res = dp[1];
        dp = vector<int> (n,0);
        dp[n-2] = nums[n-2];
        for(int i=n-3;i>=0;--i) {
        	dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
        }
        return max(res,dp[0]);
    }

};


//空间复杂度的优化 只需要两个变量
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n ==1) return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
    int robber(vector<int>&nums, int begin, int end){
        int pre = 0, cur = 0;
        for(int i = begin; i<= end; i++){
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};