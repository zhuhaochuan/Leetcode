/*
分析：给出一个数组，包含0-n这个n个元素中的n-1个
找出不在其中的那个元素
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(!nums.size()) return 0;
        int sum =0;
        for(int each : nums) sum += each;
        return nums.size()*(1 + nums.size())/2 - sum;
    }
};