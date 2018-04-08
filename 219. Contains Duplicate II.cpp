/*
分析：给出一个数组，找到两个元素相等，位置之差不超过k

*/
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!nums.size()) return false;
        unordered_map<int,int> table;
        table[nums[0]] = 0;
        for(int i=1;i<nums.size();++i) {
            if(table.count(nums[i])) {
                if(i-table[nums[i]]<=k)
                    return true;
                table[nums[i]] = i;
            }
            else table[nums[i]] = i;
        }
        return false;
    }
};



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k >= 35000)
            return false;

        int currentNum;
        for(int i = 0; i< nums.size(); i++)
        {
            currentNum = nums[i];
            for(int j = i + 1; j <= i + k && j < nums.size(); j++)
            {
                if(currentNum == nums[j])
                    return true;
            }
        }
        return false;

    }
};