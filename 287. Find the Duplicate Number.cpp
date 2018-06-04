/*
分析：找出一个数组当中的重复的那个元素
条件：数组长度为n+1 出现的元素为1~n
	使用o(1)的空间，o(n*2)以内的时间
	原始数组只读不可写
	example：
	Input: [1,3,4,2,2]
	Output: 2
	1-3-2-4-2-4-2-4....
	s:1-3-2-4
	f:3-4-4-4-2-4-2
	s:1-3-2
 */


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size(),s = 0,f = 0;

        do{
        	s = nums[s];
        	f = nums[nums[f]];
        } while(s!=f);

        s = 0;
        while(s!=f) {
        	s = nums[s];
        	f = nums[f];
        }
        return f;
    }
};