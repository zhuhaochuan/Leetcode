/*
分析：给出一系列整数 找到只出现一次的数 其他的数均出现两次
线性时间 且不采用额外的空间
这个题目的套路已经遇到过了
就是采用逐个相异或的方式 最后剩下的就是所求的那个单一的数
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto each : nums) {
        	res = each^res;
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};