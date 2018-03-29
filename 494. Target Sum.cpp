/*
分析：给出一个整型数组，在每个元素前面加上+或者-号使得这些元组组成的表达式的和为目标值得可能数
每个元素大于等于0
比如n个数一共2^n种可能，一一枚举指数级别时间复杂度，肯定太高。
[1,1,1,1,1] 5

这道题目真的挺有意思的：
首先如果采用暴力解法，必然是指数级别的复杂度
 */

//dfs 做法 时间复杂度为o(2^n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        dfs(res,nums,0,0,S);
        return res;
    }
    void dfs(int& res,vector<int>& nums,int sum,int index,int S) {
    	if(sum==S&&index==nums.size()) {
    		++res;
            return;
        }
    	else if(index<=nums.size()-1){
    		dfs(res,nums,sum+nums[index],index+1,S);
    		dfs(res,nums,sum-nums[index],index+1,S);
    	}
    }
};

//dp 做法 时间复杂度为o(n*l) n为输入数组的长度，l为target的大小
//通过数学推导将问题转化为等价问题
//求解一组数当中的子集和为一个目标值，这个问题采用动归的法
//按照当前集合当中含有的数字，以及当前处理的数字进行建模
//如果当前处理的数字是1那么需要达到的sum=9，那么当前可能达到和为9的可能数为dp[9]=dp[9]+dp[9-1]
//分析：这个dp[9]为达到sum=9的所有可能，这个值不是线性得到的，是一个随着处理的元素不同而变化的，
//当前处理的是1，所以dp[9]就等于其之前的状态加上我们得到的dp[8]的状态和，因为得到了dp[8]再加上当前处理的1就是9.
//同理将所有的nums中的元素按照该方法进行遍历，最终将得到dp[9]的最终状态。
//这样的好处是减少了很多不必要的计算，只计算我们所需要用到的可能
//并且从后往前计算就是计算当前的dp[i]只用到上一个元素得到的初始值，并不是使用的当前更新的值，因为当前的元素并不能重复使用。
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
        }
        if (sum < S || (sum + S) % 2 != 0) {
            return 0;
        }
        int target = (S + sum) / 2;
        vector<int> dp(target+1,0)
        dp[0] = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

