/*
分析：改变最多一个元素使得数组可以变成一个递增数组
除了一个元素之外其他的元素满足递增
[3,4,2,3]
3 4 4
如果nums[i]>nums[i+1]
那么这两个元素之中至少需要修改一个
如果nums[i-1]>nums[i+1]，那么就只需要将nums[i+1]改成nums[i]就可以了
如果nums[i-1]<nums[i+1],那么也只需要将nums[i]改成nums[i+1]，nums[i+1]并不用改，这一点就不用考虑
最终的目的是使得nums[i+1]最小，使得后面的最大可能的实现递增
如果再次出现非递增就返回fasle
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return true;
        bool tag = false;
        for(int i=1;i<n;++i) {
        	if(nums[i]<nums[i-1]) {
        		if(tag) return false;
        		if(i>=2&&nums[i]<nums[i-2])
        			nums[i] = nums[i-1];
        		tag = true;
        	}
        }
        return true;
    }
};

