/*
使用线性时间得到一个数组的第三大元素
如果不存在第三大元素返回数组最大元素

方案1先排序，逐个遍历达到第三个最大元素就停止
方案2使用三个变量存储第1，2，3大元素
 */

//方案1
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    	sort(nums.begin(),nums.end(),greater<int>());
        if(nums.size()<3) return nums[0];
        int n = nums.size(),tag = 0,max = INT_MAX;
        for(int i=0;i<n;++i) {
        	if(nums[i]<max) {
        		++tag;
                max = nums[i];
            }
        	if(tag==3)
        		return nums[i];
        }
        return nums[0];
    }
};

//方案2
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int flag = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN)
                flag = 1;
            if (max < nums[i]) {
                max3 = max2;
                max2 = max;
                max = nums[i];
            } else if (max2 < nums[i] && max > nums[i]) {
                max3 = max2;
                max2 = nums[i];
            } else if (max3 < nums[i] && max2 > nums[i])
                max3 = nums[i];
        }

        if (max3 != INT_MIN || (max3 != max2 && flag == 1))
            return max3;
        else
            return max;
    }
};