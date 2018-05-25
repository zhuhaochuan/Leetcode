/*
分析：删除出现次数大于2的元素中多余次数的元素，保持其他元素相对位置
原始数组是有序的，
[0,0,1,1,1,1,2,3,3]

 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size(),id = 1,count = 1;

        for(int i=1;i<n;++i) {
        	if(nums[i]==nums[i-1]) {
        		++count;
        		if(count<=2) {
        			nums[id++] = nums[i];
        		}
        	}
        	else {
        		count = 1;
        		nums[id++] = nums[i];
        	}
        }
        return id;
    }
};

//一样的思路简练的答案 不用再计数出现了多少个 直接和前面第二个比如果不相等直接放如果相等那么跳过就好
//这里的两个指针体现在一个指针是遍历原始数组的指针一个指针是指向要放的位置的指针，达到条件才放置。相当于对第一个指针遍历的数组进行就地筛选。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

