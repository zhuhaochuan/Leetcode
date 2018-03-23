/*
给定一个数组 和起始位置得到这个位置之间的元素的和
这个数组不会改变但是对于求解范围元素和的函数会被多次调用
[-2, 0, 3, -5, 2, -1]
[-2, -2, 1, -4, -2, -3]

多次调用那么肯定不需要每次都是从起始位置求和到结束位置
使用一个dp[i] 表示从头到当前位置的元素和
那么i-j之间的元素和为dp[j]-dp[i-1]
如果i-1小于0那么就补0


 */
class NumArray {
public:
	vector<int> dp;
    NumArray(vector<int> nums) {
    	dp.push_back(0);
    	for(auto each : nums) {
    		dp.push_back(dp.back() + each);
    	}
    }

    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

//下面这样写更快
class NumArray {
public:
    vector<int> sum;
    int tmp=0;
    NumArray(vector<int> nums) {
        sum.push_back(tmp);
        for(int i=0;i<nums.size();i++){
            tmp+=nums[i];
            sum.push_back(tmp);
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */