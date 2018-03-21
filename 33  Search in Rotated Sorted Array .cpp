/*
这种采用库函数的方式不推荐 为什么呢应为都不知道人家底层的实现 所以基本只是 调用的接口
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	    auto bounds = equal_range(nums.begin(), nums.end(), target);
	    if (bounds.first == bounds.second)
	        return {-1, -1};
	    return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
	}
};


/*
这种方式 采用找到下界的方式 找到目标值得下界的位置
再去找到比目标值大1的值下界的位置
再去判断这两个值得位置关系从而决定输出
找到元素的方式采用的就是常见的二分搜索
在连续空间操作当中最常使用的方式就是二分搜索
找下界的方式和二分搜索一样就是判断的符号改变
 */
vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target+1)-1;
    if (idx1 < nums.size() && nums[idx1] == target)
        return {idx1, idx2};
    else
        return {-1, -1};
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                std::vector<int> res(2, 0);
                if (nums[low] == target)
                    res[0] = low;
                if (nums[high] == target)
                    res[1] = high;
                for (int j = mid; j >= low; j--)
                {
                    if (nums[j] != target)
                    {
                        res[0] = j + 1;
                        break;
                    }
                }
                for (int i = mid; i <= high; i++)
                {
                    if (nums[i] != target)
                    {
                        res[1] = i - 1;
                        break;
                    }
                }
                return res;
            }
        }
        return { -1, -1 };
    }
};