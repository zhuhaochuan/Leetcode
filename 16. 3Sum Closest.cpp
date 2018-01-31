/*
分析：给出一个整数数组 找到数组中的三个数的和 与目标数最接近 得到这个值
S = {-1 2 1 -4}, and target = 1
-4 -1 1 2
如果按照之前的3sum的方法去求其实方案差不多
但是有细微的差别
先对于原始数组排序
如果当前的元素的值大于等于目标值那么就直接跳出

0 1 1 1
100
-3 -2 1 4
-4
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX,len = nums.size(), min = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++) {
        	if(nums[i]>=target&&nums[i+1]>=0) {//提前终止循环
                if(abs(target-(nums[i]+nums[i+1]+nums[i+2]))<res)
                    return nums[i]+nums[i+1]+nums[i+2];
                else return res;
            }
        	int l = i + 1,r = len - 1;
        	while(l<r) {
        		int temp = nums[i] + nums[l] + nums[r];
        		if(abs(target-temp)<min) {
                    res = temp;
                    min = abs(target-temp);
                }
        		if(temp>target) r--;
        		if(temp<target) l++;
        		if(temp==target) return target;
        	}
        }
        return res;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min_abs = numeric_limits<int>::max();
        int closest_sum = 0;
        for (int p1 = 0; p1 < n; ++p1) {
            int p2 = p1+1;
            int p3 = n-1;
            while (p2 < p3) {
                int sum = nums[p1] + nums[p2] + nums[p3];
                int dist = abs(sum - target);
                if (dist < min_abs) {
                    min_abs = dist;
                    closest_sum = sum;
                }
                if (sum < target) ++p2;
                else if (sum > target) --p3;
                else return target;
            }
        }
        return closest_sum;
    }
};