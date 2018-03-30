/*
分析：给出一个正整数数组，找出所有的组合使得和为目标值
每一个元素可以重复使用，并且不同顺序算作不同的序列。
将目标值减去数组当中每一个元素得到缩小的目标值
持续将目标值缩小，直到目标值缩小到0说明得到一个解
这是自顶向下的方式进行求解，这样的求解需要展开太多的项，也方便程序书写。
所以采用自底向上的方式，dp[i]代表达到目标值i所需要的可能数
 */
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
//递归方式
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        sort(nums.begin(),nums.end());
        if(target<nums[0]) return 0;
        for(int i=1;i<target+1;++i) {
        	dp[i] = helper(nums,i,dp);
        }
        return dp[target];
    }

    int helper(vector<int>& nums,int j, vector<int>& dp) {
    	int res = 0;
    	for(int i=0;i<nums.size();++i) {
    		if(j-nums[i]>=0) {
    			res += dp[j-nums[i]];
    		}
            else return res;
    	}
    	return res;
    }
};
//改进版本 不需要给原始数组进行排序，
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        //sort(nums.begin(),nums.end());
        //if(target<nums[0]) return 0;
        for(int i=1;i<=target;++i) {
        	dp[i] = helper(nums,i,dp);
        }
        return dp[target];
    }

    int helper(vector<int>& nums,int j, vector<int>& dp) {
    	int res = 0;
    	for(int i=0;i<nums.size();++i) {
    		if(j-nums[i]>=0) {
    			res += dp[j-nums[i]];
    		}
            //else return res;
    	}
    	return res;
    }
};
//迭代的方式
class Solution {
public:
    int combinationSum4(vector<int>& A, int k) {
        int dp[k+1] = {};
        dp[0] = 1;
        int n = A.size();
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - A[j] >= 0) {
                    dp[i] += dp[i-A[j]];
                }
            }
        }
        return dp[k];
    }
};