//分析：找到一个无序数组当中第k大的元素
//最简单的做法就是将原始数组排序然后遍历排好序的数组
//快速排序带来的时间复杂度为o(nlog(n))
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};


//是否可以优化？采用堆的方式更好因为只需要维护一个只有k个元素的堆，每次进来的元素当堆的大小超过k的时候就pop堆顶的元素
//这样只需要构建一个k个元素的堆，每次进来一个元素找到这个元素该放置的位置只需要log(k)的时间复杂度
//总的复杂度为o(nlog(k))是低于前一中方法的。
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
};