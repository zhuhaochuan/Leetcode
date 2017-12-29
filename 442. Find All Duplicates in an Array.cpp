/*
分析：需要找到所有的出现两次的数字
 */

//采用set的方式
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> v;
        unordered_set<int> s;
        for(auto each : nums) {
        	if(s.find(each)==s.end())
        		s.insert(each);
        	else
        		v.push_back(each);
        }
        return v;
    }
};

//采用map的方式
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> v;
        unordered_map<int,int> s;
        for(auto each : nums) {
        	if(s[each]==1)
        		v.push_back(each);
        	else
        		s[each] = 1;
        }
        return v;
    }
};

// 这个思路真的是非常的黑科技 没有用任何额外的空间就实现了
//简单来说就是遍历数组 对于处理的数n将数组对应的n-1的位置的数进行判断
//因为处理的数都大于0 所以如果对应位置的数大于0 就取反  
//当遇到的数为负数的时候 说明这个位置的数已经遇到一次了
//也就是说对应的位置n遇到了两次就将其加入
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int n: nums) {
            n = abs(n);

            // Mark number at index n - 1 -ive
            if (nums[n - 1] > 0) {
                nums[n - 1] = -nums[n - 1];
            } else {
                 result.push_back(n);
            }
        }

        return result;
    }
};

