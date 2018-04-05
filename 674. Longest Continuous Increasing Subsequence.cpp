/*
分析：找到最长的递增连续子序列
递增必须大于，不包括等于
必须连续，不能分隔
[1,3,5,4,7]
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n==1) return 1;
        int len = 1,max_len = 1;
        int pre = nums[0];
        for(int i=1;i<n;++i) {
        	if(nums[i]>pre) {
        		++len;
        		max_len = len>max_len?len:max_len;
        	}
        	else len = 1;
        	pre = nums[i];
        }
        return max_len;
    }
};