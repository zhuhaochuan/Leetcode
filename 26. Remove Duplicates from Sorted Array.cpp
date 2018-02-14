/*
分析：就是给定一个排好序的数组
删除重复的元素 返回新数组的长度
只能在原有的数组上修改

如果光是得到长度 其实很简单
遍历一遍整个数组
使用一个变量去保存上一个处理的元素的值
如果下一个与之不同就更新
如果相同就在原始长度上减一

事实上这道题目 十分之蛋疼
是让我们返回新的长度没错
同时也需要改变原始数组
使得原始数组的前那么多个元素构成那个新的数组
1 1 1 1 2 3 3 4
1 2
1
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len==1||len==0) return len;
        int temp = nums[0],count = 1;
        for(int i=1;i<len;i++) {
        	if(nums[i]!=temp) {
        		temp = nums[i];
        		nums[count] = temp;
        		++count;
        	}
        }
        return count;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int newSize = 1;
        for(int i = 1; i < size; i++)
            if(nums[i] != nums[i-1])
                nums[newSize++] = nums[i];
        return newSize > nums.size() ? nums.size() : newSize;
    }
};