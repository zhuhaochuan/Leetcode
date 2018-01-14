/*
分析：找到一个数组当中缺省的数字
出现的数字在1-n之间
n为数组的长度
不采用额外的空间 和o(n)的时间复杂度

这道题目关键在于不适用额外的空间
那么就必然需要对利用原始的数组 改变元素的值给以区分
这里就用到了数组的下标和对应数的关系
当遍历原始数组的时候
我们将对应当前元素代表的位置也就是nums[i-1]的元素置为相反数
细节：如果这个位置的元素已经是负数表示已经访问过其一次了 不用再改变
那么整个遍历一遍下来 出现的数对应的位置的元素都已经置为负数
而未出现的数对应的位置的元素必然还是正数
再次遍历一遍现在的数组将大于0元素对应的下标所对应的值取出就ok
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};