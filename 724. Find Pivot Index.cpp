/*
分析：数组左边到当前元素的和与数组右边到当前元素的和相等
如果没有这样的数返回-1 如果存在多个这样的数返回最左边的坐标
*/
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n-1;
        if(n==2) return -1;
        int sum = accumulate(nums.begin(),nums.end(),0),temp = 0;
        for(int i=0;i<n;++i) {
            temp += nums[i];
            if(sum + nums[i] == 2 * temp)
                return i;
        }
        return -1;
    }
};