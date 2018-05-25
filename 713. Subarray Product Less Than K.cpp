/*
Input: nums = [10, 5, 2, 6], k = 100
Output: 8

 */

//子序列
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size(),res = 0;
        helper(nums,k,res,0,1);
        return res;
    }

    void helper(vector<int>& nums, int k,int& res,int l,int cur) {
    	for(int i=l;i<nums.size();++i) {
    		if(cur*nums[i]<k) {
    			++res;
    			helper(nums,k,res,i+1,cur*nums[l]);
    		}
    		else return;
    	}
    	return;
    }
};

//注意是求的子串 必须连续 时间复杂度为o(n)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];

            while (prod >= k) prod /= nums[left++];//如果超过k了那么left需要前移

            res += i - left + 1; //每次计算的是以当前遍历到的元素为结尾的子串的数量
        }
        return res;
    }
};

//连续子串的可能数
//我们不可能在还没有遍历到后面元素的时候就知道以当前遍历的元素为开头的子串有多少个
//但是遍历到当前位置，我们可以知道以当前元素结尾的子串有多少个
//在这道题目当中，就是所维持的滑动窗口的长度
