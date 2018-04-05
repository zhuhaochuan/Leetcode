/*
分析：给出一个正整数构成的数组，判断这个数组是否可以拆分成两个和一样的集合。
[2,2,6]
[2,2,2]
[1, 2, 3, 5]
如果可以拆分成两个和一样的集合：首先整个数组的和必然为偶数否则无法拆分
不能有一个元素的值大于总和的一半。
 */
//我也是醉了。。。。一直在想有什么好的解法。。。
//没想到好的方式只能使用暴力解法+减枝
//但是居然击败了100%。。。。。
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if(!nums.size()) return true;
    	int n = nums.size(),sum = 0;
    	for(int each : nums) {
    		sum += each;
    	}
    	if(sum%2) return false;
        sort(nums.begin(),nums.end(),greater<int>());
        sum /= 2;
        if(nums[0]>sum) return false;
        return helper(nums,0,sum);
    }
    bool helper(vector<int>& nums,int x,int sum) {
    	if((sum-nums[x])==0)
    		return true;
    	else if((sum-nums[x])<0)
    		return false;
    	for(int i=x+1;i<nums.size();++i) {
    		if(helper(nums,i,sum-nums[x]))
    			return true;
    	}
    	return false;
    }
};


//刷表法 非常经典的刷表法
//随着遍历到的信息增多，dp表里的信息逐步更新积累。
//我们需要的结果可能就是表中某一个位置的元素
//比如求解最值问题，就需要刷完所有信息，最终表中的这个位置元素的值才是最终的结果
//如果只是判断，那么在过程中只要查看这个位置是否出现某个标识
//这就像自顶向下推，我要这个结果看得到这个结果的先决条件有没有
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);//标准库求和函数
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            if(dp[target]) return true;
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp.back();
    }
};

//bitset的方式牛逼了。。。关键是怎样保持所有元素相加和的可能！！！
//比如a + b = c
//那么bits[a] = 1
//现在讲bits左移b位那么bits[a+b]必然为1 和为a+b的情况被标识出来了
//同时最低为的1被移到了b位所以加数b被标识出来了
//同时移位之后在和原来的相或：保持原来低位的所有的1也就是保留原来的a
//就这样a,b,a+b，三个数都在bits相应的位置被标识出来
//当再次加上一个数的时候相当于同时进行a,b,a+b和新来的c相加重复以上操作
//最终所有的加数和可能得到的和全部被标识出来
//总之可以实现一个集合当中所有子集元素相加和的可能情况
bool canPartition(vector<int>& nums) {
    bitset<5001> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (auto n : nums) bits |= bits << n;
    return !(sum & 1) && bits[sum >> 1];
}