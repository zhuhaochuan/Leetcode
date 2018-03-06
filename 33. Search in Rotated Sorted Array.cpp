/*
分析： 给出一个不包含重复的升序序列 这个序列在某个位置发生了翻转
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
给出一个target值 在序列当中寻找 如果找到就返回这个值得位置否则返回-1
因为这个序列发生了翻转 所以单方面从序列的头往后搜索必然不够快 也没有足够利用给出的信息
整个序列的最大值必然出现在序列中间某个位置
如果这个值小于第一个元素 那么就从序列的尾部搜索
如果这个值大于第一个元素 那么久往后搜索并且通过比较前后两个元素的大小可以提前结束判断

我的思路没问题
但是即使这个序列被旋转了
但是在各个部分这个序列还是有序的那就可以依旧采用二分搜索降低时间复杂度
关键就是将序列按照某种方式还原成原始的有序序列 这种对于规则的还原就是关键
 */
//理解错误
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int pivot = pivot_index(nums);//首先找到那个旋转的位置

		int low = 0;
		int high = nums.size() - 1;
		while(low <= high) {
			int mid = (low + high) / 2;
			int real_mid = (mid + pivot) % nums.size();//骚操作
			if (nums[real_mid] == target)
				return real_mid;
			if (nums[real_mid] > target)
				high = mid - 1;//这里和二分法一致
			else
				low = mid+ 1;
		}

		return -1;
	}
//采用两个指针的方式找到序列当中的那个旋转位置
	int pivot_index(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		while(low < high) {
			auto mid = (low + high) / 2;
			if (nums[mid] > nums[high])
				low = mid + 1;
			else
				high = mid;
		}

		return low;
	}
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int len = nums.size();
        if(!len) return -1;
    	if(len==1) return nums[0]==target?0:-1;
    	if(target<nums[0]) {
    		int j = len-1;
    		while(j!=0) {
    			if(target==nums[j]) return j;
    			if(nums[j-1]<nums[j])
    				--j;
    			else break;
    		}
    		return -1;
    	}
    	else if(target>nums[0]) {
    		int i = 1;
    		while(i<len) {
    			if(target==nums[i]) return i;
    			if(nums[i+1]>nums[i])
    				++i;
    			else break;
    		}
    		return -1;
    	}
        else return 0;
    }
};