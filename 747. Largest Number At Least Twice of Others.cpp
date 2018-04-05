/*
分析：判断数组当中是否有一个数是其他任意一个数的至少两倍
[1, 2, 3, 4]
只需要找到最大的元素和第二大的元素就可以，需要返回下标所以不可以改变原始数组
一次遍历得到最大和第二大的元素
但凡出现除法 切记分母为0
最好不要使用除法
 */
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        int n = nums.size();
        if(n==1) return 0;
        int max1 = nums[0],max2 = -1,index1 = 0;
        for(int i=1;i<n;++i) {
        	if(nums[i]>=max1) {
        		index1 = i;
                max2 = max1;
        		max1 = nums[i];
        	}
            else if(nums[i]>max2)
                max2 = nums[i];
        }
        if(max1>= (max2<<1))
        	return index1;
        else return -1;
    }
};