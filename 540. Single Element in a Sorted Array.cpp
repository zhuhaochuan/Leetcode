/*
题目很简单 就是在排好序的数组当中找到只出现一次的数 其他的数出现两次
时间复杂度logN 空间复杂度o(1)
[1,1,2,3,3,4,4,8,8]
我的思路是采用类似二分搜索的方式因为这个数组的长度必然是奇数
首先找到中间的数判断其和左边的数是否相等 如果单个的出现在左子序列则会不相等
如果相等则出现在右子序列
递归或者迭代的判别
直到找到一个点的值和左右均不相等就是答案

没考虑到 特殊情况 长度为3 时
没考虑到边界情况
比如单个值出现在第一个或者最后一个
 */


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        int len = nums.size();
        if(nums[len-1]!=nums[len-2]) return nums[len-1];
    	int i = len/2;
    	int res = nums[i];

    	while(!(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1])) {
    		if(nums[i]!=nums[i-1]) {
    			if(len == 3)
    				i = i - 1;
    			else
    				i = i/2;
    		}
    		else {
				if(len==3)
					i = i + 1;
				else
					i = i + (len-i)/2;
			}
            res = nums[i];
    	}
    	return res;
    }
};


//你妈这个答案真你妈人才 我是服气的
//任何数和0按位异或都是自己本身
//一个数自己和自己异或为0
//所以用0和数组中每个元素异或 中间出现两次的都会消除影响
//最后相当于0和单个出现的数异或 得到这个数本身！！！
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for(auto i:nums){
            ret ^=i;
        }
        return ret;
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        size_t left = 0, right = nums.size() - 1;
        while( left < right ) {
            size_t mid = (left + right) / 2;
            if( mid % 2 == 1 )
                mid--;
            if( nums[mid] == nums[mid + 1] )
                left += 2;
            else
                right = mid;
        }

        return nums[left];
    }
};