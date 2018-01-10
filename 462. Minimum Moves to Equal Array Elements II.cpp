/*
分析： 给定一个整型数组
求最少的移动使得数组变成一个所以元素相等的数组
每一次移动只能使一个元素加1或者减一
想法：如果能够确定最后统一的那个值就好办了
找到这个值之后 只要遍历一遍数组就可以得到结果
这个值得选取决定最后的次数
会不会有几种相同的可能？
1122
这个选取1 和 2 是一样的
求均值？1 2 3 均值为2
如果是这样呢 1 1 100 均值为50
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(!nums.size()) return 0;
        int sum = 0,len = nums.size();
        sort(nums.begin(),nums.end());
        int center = nums[len/2];
        for(int each : nums) {
        	sum += abs(each - center);
        }
        return sum;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n/2; ++i) res += (nums[n-1-i]-nums[i]);
        //精彩的一步 将减少一半的循环
        return res;

    }
};


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0, n = nums.size(), mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        //这个排序算法 之前没用过
        for (int i = 0; i < n; ++i) {
            res += abs(nums[i] - nums[mid]);
        }
        return res;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {

        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int odd=(nums.size()%2);//表示奇偶
        int med=nums.size()/2;
        if(!odd) med--;
        int sum=0;
        int tar=nums[med];
        for(auto i:nums)sum+=abs(i-tar);
        return sum;
    }
};