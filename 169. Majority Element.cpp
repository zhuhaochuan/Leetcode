/*
分析：找到出现次数大于n/2的元素

 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(!nums.size()) return 0;
        map<int,int> table;
        for(int each : nums) {
        	++table[each];
        	if(table[each]>nums.size()/2)
        		return each;
        }
        return 0;
    }
};

//312331
//因为出现次数大于n/2的元素必然出现的次数比其他所有的元素的总和还多
//必然会出现至少两个最大出现次数元素连续出现的情况，那么只要下一个不同元素
//ctr就减1，但是对于连续出现的来说必然可以等到下一个再出现自己还没有被更新
//所以最终得到了最大出现次数的元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int maj = nums[0];
        int ctr = 1;

        for (int i = 1; i<nums.size(); i++) {
            if (ctr == 0)
                maj = nums[i];
            if (nums[i] == maj)
                ctr++;
            else
                ctr--;



        }
        return maj;
    }
};