/*
找到目标值在原升序序列当中的位置
如果目标元素不在序列当中就找到该元素按照顺序插入后所在的位置

 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size()) return 0;
        int l = 0, r = nums.size() - 1, mid = (l+r)/2;
        while(l<r) {
        	if(nums[mid]<target)
        		l = mid + 1;
        	else if(nums[mid]>target)
        		r = mid - 1;
        	else return mid;
            mid = (l+r)/2;
        }
    	return nums[mid]<target?mid+1:mid;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<target)
                low=mid+1;
            if(nums[mid]>target)
                high=mid-1;
            if(nums[mid]==target)
                return mid;
        }
        return low;
    }
};

/*
造几个轮子
lower_bound()
up_bound()
 */

//输入一个升序数组 找到target在数组当中出现的最低位置
int lower_bound(vector<int>& nums, int target) {
	if(!nums.size()) return 0;
	int l = 0, r = nums.size()-1;
	while(l<r) {
		int mid = (l+r)/2;
		if(nums[mid]<target)
			l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
//找到target 在数组当中最高的位置
int up_bound(vector<int>& nums, int target) {
	if(!nums.size()) return 0;
	int l = 0, r = nums.size()-1;
	while(l<r) {
		int mid = (l+r)/2;
		if(nums[mid]>target)
			r = mid - 1;
		else l = mid + 1;
	}
	return r;
}
