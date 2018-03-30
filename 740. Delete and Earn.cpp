/*
分析：给出一个数组，我们可以做出如下操作：
删除一个元素即得到该元素的分数，但是同时将会删除所有等于nums[i]-1和nums[i]+1的元素
最终删除所有的元素后得到的最高分数为所求分数。
nums = [2, 2, 3, 3, 3, 4]
 */
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size(),res = 0,max1 = 0,max2 = 0;
        vector<int> dp(nums[n-1]+1,0);
        for(int i=0;i<n;++i) {
        	if(nums[i]<=0) continue;
        	if(nums[i]==1) {
                dp[nums[i]] += nums[i];
                max1 = dp[nums[i]];
            }
        	else {
        		dp[nums[i]] = dp[nums[i]]>0?dp[nums[i]] + nums[i]:(nums[i]==nums[i-1]+1?max(dp[nums[i]-2],max2) + nums[i]:max(dp[nums[i]-2],max1)+nums[i]);
        	}
        	if(dp[nums[i]]>res) res = dp[nums[i]];
        	if(nums[i]>1) {
                if(nums[i]!=nums[i-1])
	        	    max2 = max1>max2?max1:max2;
	        	if(dp[nums[i]]>max1) max1 = dp[nums[i]];
	        }
        }
        return res;
    }
};

//输入偏贪心算法 取当前最优情况
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sums(*max_element(nums.begin(), nums.end()), 0);
        for(int i: nums) sums[i-1]+=i;
        //vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),  0));
        if(nums.size()<2) return sums.back();
        vector<int> dp(sums.size(), 0);
        dp[0] = sums[0];
        dp[1] = max(sums[0], sums[1]);
        for(int i=2; i< sums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+sums[i]);
        }
        return dp.back();
    }
};