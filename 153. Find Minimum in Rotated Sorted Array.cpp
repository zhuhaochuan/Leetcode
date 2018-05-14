//分析:一个从小到大排序的数组可能被翻转了一部分
//需要找到其中最小的元素 数组当中没有重复的元素
// 二分搜素

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(!nums.size()) return 0;
        int l = 0,r = nums.size()-1,mid = 0;
        while(l<r) {
        	mid = l + (r-l)/2;
        	if(nums[l]<nums[r])
        		return nums[l];
        	if(nums[mid]<nums[r])
        		r = mid;
        	else l = mid + 1;
        }
        return nums[l];
    }
};

