/*
分析：找出数组当中三个元素的乘积最大的三个元素
数组当中的元素有正有负。
-10 -2 -1 -1 10 100
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int r_max = nums[n-1] * nums[n-2] * nums[n-3];
        int l_max = nums[0] * nums[1] * nums[n-1];
        return r_max>l_max?r_max:l_max;
    }
};