/*
分析：得到一个数组当中连续1的最长的长度
思路就是 遍历整个数组如果是1 就count++ 不是1就count清0 且记录当前的count
 */


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(!nums.size()) return 0;
        int res = 0, count = 0;
        for(auto each : nums) {
        	if(each==1) count++;
        	else {
        		if(count>res) res = count;
        		count = 0;
        	}
            if(count>res) res = count;//要注意最后的count并没有被处理需要单独处理
        }
        return res;
    }
};